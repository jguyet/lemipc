/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_protocol_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:44:23 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 18:44:24 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

#include <unistd.h>

void	wait_unlock_ipc(struct s_bytebuffer *buffer)
{
	while (header_is_writable(buffer) == false) {
		ft_printf("Wait locked\n");
		usleep(50000);
	}
}

int	get_header_segment_size(struct s_bytebuffer *buffer)
{
	return (read_int_on_pos(buffer, 0));
}

BOOLEAN	header_is_writable(struct s_bytebuffer *buffer)
{
	return (read_int_on_pos(buffer, 4) == UNLOCK);
}

int	get_header_max_player_id(struct s_bytebuffer *buffer)
{
	return (read_int_on_pos(buffer, 8));
}

int	get_header_number_of_player(struct s_bytebuffer *buffer)
{
	return (read_int_on_pos(buffer, 12));
}

int	get_header_players_offset(struct s_bytebuffer *buffer)
{
	return (read_int_on_pos(buffer, 16));
}

void	write_header_segment_size(struct s_bytebuffer *buffer, int segment_size)
{
	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	write_int_on_pos(buffer, 0, segment_size);
	unlock_ipc(buffer);
}

void	unlock_ipc(struct s_bytebuffer *buffer)
{
	write_int_on_pos(buffer, 4, UNLOCK);
}

void	lock_ipc(struct s_bytebuffer *buffer)
{
	wait_unlock_ipc(buffer);
	write_int_on_pos(buffer, 4, LOCK);
}

void	write_header_max_player_id(struct s_bytebuffer *buffer, int id)
{
	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	write_int_on_pos(buffer, 8, id);
	unlock_ipc(buffer);
}

void	write_header_number_of_player(struct s_bytebuffer *buffer, int n)
{
	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	write_int_on_pos(buffer, 12, n);
	unlock_ipc(buffer);
}

void	write_header_players_offset(struct s_bytebuffer *buffer, int offset)
{
	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	write_int_on_pos(buffer, 16, offset);
	unlock_ipc(buffer);
}

void	add_one_number_of_player(struct s_bytebuffer *buffer)
{
	int number;

	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	number = get_header_number_of_player(buffer);
	write_int_on_pos(buffer, 12, number + 1);
	unlock_ipc(buffer);
}

void	remove_one_number_of_player(struct s_bytebuffer *buffer)
{
	int number;

	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	number = get_header_number_of_player(buffer);
	write_int_on_pos(buffer, 12, number - 1);
	unlock_ipc(buffer);
}

int		get_next_player_id(struct s_bytebuffer *buffer)
{
	int id;

	wait_unlock_ipc(buffer);
	lock_ipc(buffer);
	id = get_header_max_player_id(buffer);
	write_int_on_pos(buffer, 8, id + 1);
	unlock_ipc(buffer);
	return (id);
}
