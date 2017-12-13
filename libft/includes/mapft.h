/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:41:51 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/23 15:41:53 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPFT_H
# define MAPFT_H

# ifdef PROG_MAP_FT

#  include <stdlib.h>
#  include <limits.h>
#  include <libft.h>
#  include <printf.h>

# endif

typedef struct		s_hash
{
	void			*data;
	void			*key;
	struct s_hash	*next;
	struct s_hash	*prev;
}					t_hash;

typedef struct		s_hashmap
{
	t_hash			**hashtable;
	int				(*add)();
	void			*(*get)();
	int				size;
	char			*(*tostring)();
	void			(*clear)();
	void			(*foreach)();
	void			(*foreach1)();
	int				(*remove)();
	int				map_size;
	int				type;
}					t_hashmap;

# ifdef PROG_MAP_FT

/*
** Functions for hashMAP
*/
int					parsekey(t_hashmap *table, void *key);
t_hash				*get_hash_element(t_hashmap *table, void *key);
void				*get_hash_value(t_hashmap *table, void *key);
int					get_hash_size(t_hashmap *table);
BOOLEAN				add_hash(t_hashmap *table, void *key, void *data);
void				clear_hashtable(t_hashmap *table);
BOOLEAN				remove_element_on_hashtable(t_hashmap *table, void *key);
char				*tostring_hashtable(t_hashmap *map);
void				foreach_hashtable(t_hashmap *table,\
					void (*func)(), void *arg);

# endif

/*
** Function initialize hashMap exemple (t_hashmap *map = newStringhashmap(10);)
*/
t_hashmap			*newintegerhashmap(int size);
t_hashmap			*newstringhashmap(int size);
void				destruct_hashmap(t_hashmap *table);

# define FOREACH_MAP(map, func, arg) map->foreach(map, func, arg)
#endif
