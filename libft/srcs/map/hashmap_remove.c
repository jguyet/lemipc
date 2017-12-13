/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/23 15:42:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PROG_MAP_FT
#include "mapft.h"

/*
** REMOVE ELEMENT METHOD
*/

BOOLEAN		remove_element_on_hashtable(t_hashmap *table, void *key)
{
	int		hashindex;
	t_hash	*element;

	if ((element = get_hash_element(table, key)) == NULL)
		return (false);
	hashindex = parsekey(table, key);
	if (element->next != NULL)
		element->next->prev = element->prev;
	if (element->prev != NULL)
		element->prev->next = element->next;
	else
		table->hashtable[hashindex] = element->next;
	free(element);
	table->size--;
	return (true);
}

/*
** CLEAR METHOD
*/

void		clear_hashtable(t_hashmap *table)
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
				free(element);
				element = tmp;
			}
			table->hashtable[i] = NULL;
		}
		i++;
	}
	table->size = 0;
}
