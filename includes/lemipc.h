/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:02:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/12 13:32:18 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

#include <libft.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <printf.h>


/*
** CREATE SEGMENT
*/
#define SHMSZ 27

#define DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY 12017

int				create_ipc_segment(key_t key);
int				get_ipc_segment(key_t key);
void			*get_ipc_segment_data(int shared_memory_id);
void			remove_ipc_segment(int shared_memory_id);


#endif
