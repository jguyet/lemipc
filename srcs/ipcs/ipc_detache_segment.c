/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipc_detache_segment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:08:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 18:08:51 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			ipc_detache_segment(void *shmaddr)
{
	int		shmid;

	if ((shmid = shmdt(shmaddr)) < 0)
	{
		if (DEBUG_MODE)
		{
			ft_printf("ipc_detache_segment shmdt exception return code (%d)\n",\
				shmid);
		}
		return (-1);
	}
	return (shmid);
}
