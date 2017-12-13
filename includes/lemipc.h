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

#define DEBUG_MODE 1

/*
** ----- HEADER PROTOCOL -----
** 4octet = ipc_memory size    00000000 00000000 00000000 00000000
** 4octet = max player ID      00000000 00000000 00000000 00000000
** 4octet = player number      00000000 00000000 00000000 00000000
** 4octet = map size           00000000 00000000 00000000 00000000
** 4octet = players pos offset 00000000 00000000 00000000 00000000
** -----                 -----
** circular MAP (\)
*/



/*
** DEFAULT MAP SIZE
*/
#define MAPSIZE (1000)
/*
** DEFAULT KEY SEGMENT
*/
#define DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY 12017

typedef struct			s_bytebuffer
{
	char				*data;
	int					position;
	int					size;
	void				(*write_int)(struct s_bytebuffer *buffer, int n);
	void				(*write_short)(struct s_bytebuffer *buffer, short n);
	void				(*write_char)(struct s_bytebuffer *buffer, char n);
	void				(*write_string)(struct s_bytebuffer *buffer, char *s);
	int					(*read_int)(struct s_bytebuffer *buffer);
	short				(*read_short)(struct s_bytebuffer *buffer);
	char				(*read_char)(struct s_bytebuffer *buffer);
	char				*(*read_string)(struct s_bytebuffer *buffer);
}						t_bytebuffer;

typedef struct			s_lem
{
	int					team;
	int					shared_segment_size;
	int					shared_segment_id;
	struct s_bytebuffer	*buffer;
}						t_lem;

int				create_ipc_segment(key_t key, int size);
BOOLEAN			ipc_segment_exists(key_t segment_key);
int				get_ipc_segment(key_t key, int size);
void			*get_ipc_segment_data(int shared_memory_id);
void			remove_ipc_segment(int shared_memory_id);
int				ipc_detache_segment(void *shmaddr);

/*
** LEMIPC
*/
struct s_lem			*newlem(void);
void					destruct_lem(struct s_lem *lem);
void					get_ipc_segment_and_play(void);
int						play(t_lem *lem);
void					create_ipc_segment_and_play(void);
/*
** BUFFER WRAPPER
*/
struct s_bytebuffer		*newbytebuffer(void *ptr, int size);
void					destruct_bytebuffer(struct s_bytebuffer *buffer);
void					write_int(struct s_bytebuffer *buffer, int n);
void					write_short(struct s_bytebuffer *buffer, short n);
void					write_char(struct s_bytebuffer *buffer, char c);
void					write_string(struct s_bytebuffer *buffer, char *str);
void					write_memory(struct s_bytebuffer *buffer, void *m, size_t size);
int						read_int(struct s_bytebuffer *buffer);
short					read_short(struct s_bytebuffer *buffer);
char					read_char(struct s_bytebuffer *buffer);
char					*read_string(struct s_bytebuffer *buffer);

#endif
