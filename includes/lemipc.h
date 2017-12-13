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

# include <libft.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <printf.h>
# include <mapft.h>

# define DEBUG_MODE 1

/*
** DEFAULT SIZE OF SEGMENT
*/
# define DEFAULT_IPC_SHARED_SEGMENT_MEMORY_SIZE 4096

/*
** DEFAULT KEY SEGMENT
*/
# define DEFAULT_KEY_IPC_SHARED_SEGMENT_MEMORY 12017

/*
** PLAYERS STATUS
*/
# define DEAD_STATUS			-1
# define WAIT_STATUS			0
# define PLAY_STATUS			1
# define WAIT_FOR_PLAY_STATUS	2

# define LOCK					1
# define UNLOCK					0

typedef struct					s_bytebuffer
{
	char						*data;
	int							position;
	int							size;
	void						(*write_int)(struct s_bytebuffer *buffer,\
								int n);
	void						(*write_short)(struct s_bytebuffer *buffer,\
								short n);
	void						(*write_char)(struct s_bytebuffer *buffer,\
								char n);
	void						(*write_string)(struct s_bytebuffer *buffer,\
								char *s);
	int							(*read_int)(struct s_bytebuffer *buffer);
	short						(*read_short)(struct s_bytebuffer *buffer);
	char						(*read_char)(struct s_bytebuffer *buffer);
	char						*(*read_string)(struct s_bytebuffer *buffer);
}								t_bytebuffer;

/*
** ----- HEADER PROTOCOL -----
** 4octet = ipc_memory size    00000000 00000000 00000000 00000000
** 4octet = next player ID     00000000 00000000 00000000 00000000
** 4octet = player numbers     00000000 00000000 00000000 00000000
** 4octet = players offset     00000000 00000000 00000000 00000000
** -----                 -----
** circular MAP (\)
*/

typedef struct					s_player
{
	int							id;
	int							team;
	int							status;
	int							x;
	int							y;
}								t_player;

typedef struct					s_lem
{
	int							team;
	int							shared_segment_size;
	int							shared_segment_id;
	struct s_bytebuffer			*buffer;
}								t_lem;

/*
** IPCS
*/
int								create_ipc_segment(key_t key, int size);
BOOLEAN							ipc_segment_exists(key_t segment_key);
int								get_ipc_segment(key_t key, int size);
void							*get_ipc_segment_data(int shared_memory_id);
void							remove_ipc_segment(int shared_memory_id);
int								ipc_detache_segment(void *shmaddr);

/*
** LEMIPC
*/
struct s_lem					*newlem(void);
void							destruct_lem(struct s_lem *lem);
void							get_ipc_segment_and_play(void);
int								play(t_lem *lem);
void							create_ipc_segment_and_play(void);

/*
** PROTOCOL_HEADER
*/
void							wait_unlock_ipc(struct s_bytebuffer *buffer);
int								get_header_segment_size(struct s_bytebuffer *buffer);
BOOLEAN							header_is_writable(struct s_bytebuffer *buffer);
int								get_header_max_player_id(struct s_bytebuffer *buffer);
int								get_header_number_of_player(struct s_bytebuffer *buffer);
int								get_header_players_offset(struct s_bytebuffer *buffer);
void							write_header_segment_size(struct s_bytebuffer *buffer, int segment_size);
void							unlock_ipc(struct s_bytebuffer *buffer);
void							lock_ipc(struct s_bytebuffer *buffer);
void							write_header_max_player_id(struct s_bytebuffer *buffer, int id);
void							write_header_number_of_player(struct s_bytebuffer *buffer, int n);
void							write_header_players_offset(struct s_bytebuffer *buffer, int offset);
void							add_one_number_of_player(struct s_bytebuffer *buffer);
void							remove_one_number_of_player(struct s_bytebuffer *buffer);
int								get_next_player_id(struct s_bytebuffer *buffer);

/*
** PLAYER
*/
struct s_player					*new_player(void);
void							destruct_player(struct s_player *player);
t_hashmap						*read_players(struct s_bytebuffer *buffer);
struct s_player					*read_player(struct s_bytebuffer *buffer);
void							write_player(struct s_bytebuffer *buffer,\
								struct s_player *player);
void							save_player(struct s_bytebuffer *buffer,\
								struct s_player *player);
t_player						*get_player(struct s_bytebuffer *buffer, int id);

/*
** BUFFER WRAPPER
*/
struct s_bytebuffer				*newbytebuffer(void *ptr, int size);
void							destruct_bytebuffer(\
								struct s_bytebuffer *buffer);
void							write_int(struct s_bytebuffer *buffer, int n);
void							write_short(struct s_bytebuffer *buffer,\
								short n);
void							write_char(struct s_bytebuffer *buffer,\
								char c);
void							write_string(struct s_bytebuffer *buffer,\
								char *str);
void							write_memory(struct s_bytebuffer *buffer,\
								void *m, size_t size);
int								read_int(struct s_bytebuffer *buffer);
short							read_short(struct s_bytebuffer *buffer);
char							read_char(struct s_bytebuffer *buffer);
char							*read_string(struct s_bytebuffer *buffer);
void							write_int_on_pos(struct s_bytebuffer *buffer,\
								int pos, int value);
int								read_int_on_pos(struct s_bytebuffer *buffer,\
								int pos);

#endif
