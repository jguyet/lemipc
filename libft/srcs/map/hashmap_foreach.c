/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_methods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:23:15 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/25 12:23:17 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PROG_MAP_FT
#include "mapft.h"

/*
** FOREACH METHOD
*/

void		foreach_hashtable(t_hashmap *table, void (*func)(), void *arg)
{
	int		i;
	t_hash	*element;
	t_hash	*tmp;

	i = 0;
	while (i < table->map_size)
	{
		if (table->hashtable[i] != NULL)
		{
			element = table->hashtable[i];
			while (element != NULL)
			{
				tmp = element->next;
				func(element->key, element->data, arg);
				element = tmp;
			}
		}
		i++;
	}
}
