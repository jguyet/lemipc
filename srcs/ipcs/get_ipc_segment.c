/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipc_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:53:01 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/12 12:53:03 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			get_ipc_segment(key_t key)
{
    int		shmid;

    if ((shmid = shmget(key, SHMSZ, 0666)) < 0)
		return (-1);
    return (shmid);
}
