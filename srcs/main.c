/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:01:22 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 15:11:44 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "lemipc.h"

void	add_new_player(t_lem *lem)
{
	t_player *player;

	player = new_player();
	player->id = get_next_player_id(lem->buffer);
	player->team = 55;
	add_one_number_of_player(lem->buffer);
	save_player(lem->buffer, player);
	t_player *test;
	ft_printf("player->id(%d), player->team(%d)\n", player->id, player->team);

	test = get_player(lem->buffer, player->id);
	ft_printf("test->id(%d), test->team(%d)\n", test->id, test->team);
	sleep(5);
}

int		play(t_lem *lem)
{
	(void)lem;
	ft_printf("PLAY\n");

	add_new_player(lem);
	return (-1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (ipc_segment_exists(DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY))
	{
		get_ipc_segment_and_play();
	}
	else
	{
		create_ipc_segment_and_play();
	}
	return (0);
}
