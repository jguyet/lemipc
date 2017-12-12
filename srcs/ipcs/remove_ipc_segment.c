/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_ipc_segment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:02:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/12 13:07:08 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		remove_ipc_segment(int shared_memory_id)
{
	struct shmid_ds	shmid_ds;
	int				cmd;
    register int    rtrn;

    cmd = IPC_RMID;
	if ((rtrn = shmctl(shared_memory_id, cmd, &shmid_ds)) == -1)
	{
		ft_printf("remove_ipc_segment remove exception return code (%d).\n", rtrn);
		return ;
	}
    ft_printf("ipcs segment removed return code (%d)\n", rtrn);
}
