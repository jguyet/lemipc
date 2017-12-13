/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_lem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:30:26 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 18:30:27 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int			get_ipc_segment_data_size(key_t key)
{
	int				shared_segment_id;
	int				shared_segment_size;
	char			*data;
	t_bytebuffer	*buffer;

	if ((shared_segment_id = get_ipc_segment(key, 4)) < 0)
		return (-1);
	if (!(data = get_ipc_segment_data(shared_segment_id)))
		return (-1);
	buffer = newbytebuffer(data, 4);
	shared_segment_size = buffer->read_int(buffer);
	destruct_bytebuffer(buffer);
	return (shared_segment_size);
}

static t_bytebuffer	*get_bytebuffer_ipc_segment_data(int shared_segement_id, size_t shared_segment_size)
{
	char			*data;
	t_bytebuffer	*buffer;

	if (!(data = get_ipc_segment_data(shared_segement_id)))
		return (NULL);
	if (!(buffer = newbytebuffer(data, shared_segment_size)))
		return (NULL);
	return (buffer);
}

void				get_ipc_segment_and_play(void)
{
	t_bytebuffer	*buffer;
	t_lem			*lem;

	ft_printf("get_ipc_segment_and_play\n");
	if (!(lem = newlem()))
		return ;
	if ((lem->shared_segment_size = get_ipc_segment_data_size(DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY)) == -1)
		return ;
	if ((lem->shared_segment_id = get_ipc_segment(DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY, lem->shared_segment_size)) < 0)
		return ;
	if (!(buffer = get_bytebuffer_ipc_segment_data(lem->shared_segment_id, lem->shared_segment_size)))
		return ;
	lem->buffer = buffer;
	lem->buffer->position += 4;
	if (play(lem) == -1)
		remove_ipc_segment(lem->shared_segment_id);
	destruct_bytebuffer(buffer);
	destruct_lem(lem);
}

void				create_ipc_segment_and_play(void)
{
	int				shared_segement_id;
	char			*data;
	t_bytebuffer	*buffer;

	ft_printf("create_ipc_segment_and_play\n");
	if ((shared_segement_id = create_ipc_segment(DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY, MAPSIZE + 4)) < 0)
		return ;
	data = get_ipc_segment_data(shared_segement_id);
	buffer = newbytebuffer(data, MAPSIZE);
	buffer->write_int(buffer, MAPSIZE + 4);
	destruct_bytebuffer(buffer);
	get_ipc_segment_and_play();
}
