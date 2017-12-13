/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_protocol_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:44:23 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 18:44:24 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

struct s_lemipc_protocol_header	*new_lemipc_protocol_header(void)
{
	struct s_lemipc_protocol_header	*new;

	if (!(new = (struct s_lemipc_protocol_header*)malloc(sizeof(struct s_lemipc_protocol_header))))
		return (NULL);
	return (new);
}

void							write_lemipc_protocol_header(\
	struct s_bytebuffer buffer,\
	struct s_lemipc_protocol_header *header)
{
	buffer->write_int(header->shared_segment_size);
	buffer->write_int(header->max_player_id);
	buffer->write_int(header->number_of_player);
	buffer->write_int(header->map_size);
	buffer->write_int(header->players_pos_offset);
}
/*
**           23
**        21 11 24
**      20 10 4 12 25
**     19 9 3 0 1 5 13
**       18 8 2 6 14
**         17 7 15
**           16
*/
