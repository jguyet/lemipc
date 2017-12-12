/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ipc_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:51:00 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/12 12:51:01 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int         create_ipc_segment(key_t key)
{
    int		shmid;

    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
		ft_printf("create_ipc_segment creation exception return code (%d)\n", shmid);
		return (-1);
    }
	ft_printf("ipcs segment %d created\n", shmid);
    return (shmid);
}
