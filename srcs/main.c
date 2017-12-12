/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:01:22 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/12 11:01:23 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int     main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

	int		shared_segement_id;
    key_t	shared_key_memory;

    shared_key_memory = DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY;

    if ((shared_segement_id = get_ipc_segment(shared_key_memory)) < 0)
    {
		if ((shared_segement_id = create_ipc_segment(shared_key_memory)) < 0)
			return (1);
    }

	remove_ipc_segment(shared_segement_id);
    return (0);
}
