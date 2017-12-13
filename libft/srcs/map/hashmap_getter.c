/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_getter.c                                   :+:      :+:    :+:   */
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
** GET ELEMENT METHOD
*/

t_hash		*get_hash_element(t_hashmap *table, void *key)
{
	int		hashindex;
	t_hash	*element;

	hashindex = parsekey(table, key);
	if (table->hashtable[hashindex] != NULL)
	{
		element = table->hashtable[hashindex];
		while (element != NULL)
		{
			if (table->type == 'i' && element->key == key)
				return (element);
			else if (table->type == 's'\
				&& ft_strcmp((char*)element->key, key) == 0)
				return (element);
			element = element->next;
		}
	}
	return (NULL);
}

/*
** GET ELEMENT VALUE METHOD
*/

void		*get_hash_value(t_hashmap *table, void *key)
{
	int		hashindex;
	t_hash	*element;

	hashindex = parsekey(table, key);
	if (table->hashtable[hashindex] != NULL)
	{
		element = table->hashtable[hashindex];
		while (element != NULL)
		{
			if (table->type == 'i' && element->key == key)
				return (element->data);
			else if (table->type == 's'\
				&& ft_strcmp((char*)element->key, key) == 0)
				return (element->data);
			element = element->next;
		}
	}
	return (NULL);
}
