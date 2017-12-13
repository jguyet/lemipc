/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:54:51 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 19:54:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

struct s_player		*new_player(void)
{
	struct s_player	*player;

	if (!(player = (struct s_player*)malloc(sizeof(struct s_player))))
		return (NULL);
	player->id = -1;
	player->team = -1;
	player->status = WAIT_STATUS;
	player->x = 0;
	player->y = 0;
	return (player);
}

void				destruct_player(struct s_player *player)
{
	free(player);
}

t_hashmap			*read_players(struct s_bytebuffer *buffer)
{
	int				save_buffer_position;
	int				i;
	t_hashmap		*map;
	struct s_player	*p;

	save_buffer_position = buffer->position;
	i = 0;
	if (!(map = newintegerhashmap(10)))
		return (NULL);
	buffer->position = get_header_players_offset(buffer);
	while (i < get_header_number_of_player(buffer))
	{
		if ((p = read_player(buffer)) != NULL)
			map->add(map, i, p);
		i++;
	}
	buffer->position = save_buffer_position;
	return (map);
}

struct s_player		*read_player(struct s_bytebuffer *buffer)
{
	struct s_player	*player;

	if (!(player = new_player()))
		return (NULL);
	player->id = buffer->read_int(buffer);
	player->team = buffer->read_int(buffer);
	player->status = buffer->read_int(buffer);
	player->x = buffer->read_int(buffer);
	player->y = buffer->read_int(buffer);
	return (player);
}

int					get_player_id_pos(struct s_bytebuffer *buffer, int id)
{
	int				save_buffer_position;
	int				i;
	int				br;
	struct s_player	*p;

	save_buffer_position = buffer->position;
	i = 0;
	br = 0;
	buffer->position = get_header_players_offset(buffer);
	while (i < get_header_number_of_player(buffer))
	{
		if ((p = read_player(buffer)) != NULL)
		{
			ft_printf("p->ID %d\n", p->id);
			if (p->id == id)
				br = 1;
			destruct_player(p);
		}
		else {
			ft_printf("NULL\n");
		}
		if (br == 1)
			break ;
		i++;
	}
	buffer->position = save_buffer_position;
	return (i);
}

t_player			*get_player(struct s_bytebuffer *buffer, int id)
{
	int				save_buffer_position;
	int				i;
	struct s_player	*p;

	p = NULL;
	save_buffer_position = buffer->position;
	i = 0;
	buffer->position = get_header_players_offset(buffer);
	ft_printf("read p____ %d\n", get_header_players_offset(buffer));
	buffer->position += (5 * 4) * get_player_id_pos(buffer, id);
	ft_printf("read p %d\n", buffer->position);
	p = read_player(buffer);
	buffer->position = save_buffer_position;
	return (p);
}

void				save_player(struct s_bytebuffer *buffer,\
					struct s_player *player)
{
	int	save_position;

	save_position = buffer->position;
	DEBUGLINE;
	buffer->position = get_header_players_offset(buffer);
	DEBUGLINE;
	buffer->position += (5 * 4) * get_player_id_pos(buffer, player->id);
	DEBUGLINE;
	ft_printf("write p %d\n", buffer->position);
	write_player(buffer, player);
	buffer->position = save_position;
}

void				write_player(struct s_bytebuffer *buffer,\
					struct s_player *player)
{
	buffer->write_int(buffer, player->id);
	buffer->write_int(buffer, player->team);
	buffer->write_int(buffer, player->status);
	buffer->write_int(buffer, player->x);
	buffer->write_int(buffer, player->y);
}
