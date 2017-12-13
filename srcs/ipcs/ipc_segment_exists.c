/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipc_segement_exists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:17:02 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 15:17:03 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

BOOLEAN		ipc_segment_exists(key_t segment_key)
{
	return (get_ipc_segment(segment_key, 1) != -1);
}
