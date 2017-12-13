/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipc_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:53:01 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 15:13:02 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			get_ipc_segment(key_t key, int size)
{
	int		shmid;

	if ((shmid = shmget(key, size, 0666)) < 0)
	{
		ft_printf("get_ipc_segment shmget exception return code (%d)\n",\
			shmid);
		return (-1);
	}
	return (shmid);
}
