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

#include "lemipc.h"

int	play(t_lem *lem)
{
	(void)lem;
	ft_printf("PLAY\n");
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
