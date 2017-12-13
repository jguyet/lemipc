/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipc_segment_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:17:21 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 15:13:35 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		*get_ipc_segment_data(int shared_memory_id)
{
	void	*shm;

	if ((shm = shmat(shared_memory_id, NULL, 0)) == (char*)-1)
	{
		if (DEBUG_MODE)
		{
			ft_printf("get_ipc_segment_data shmat exception type (NULL).");
		}
		return (NULL);
	}
	return (shm);
}
