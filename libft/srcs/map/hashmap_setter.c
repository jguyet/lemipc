/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_setter.c                                   :+:      :+:    :+:   */
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
** ADD ELEMENT BY KEY METHOD
*/

BOOLEAN		add_hash(t_hashmap *table, void *key, void *data)
{
	t_hash	*new;
	int		hashindex;
	t_hash	**element;

	if (!(new = (t_hash*)malloc(sizeof(struct s_hash))))
		return (false);
	new->key = key;
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	hashindex = parsekey(table, key);
	element = &table->hashtable[hashindex];
	if (*element != NULL)
	{
		while ((*element)->next != NULL)
			element = &(*element)->next;
		(*element)->next = new;
		new->prev = (*element)->next;
	}
	else
		table->hashtable[hashindex] = new;
	table->size++;
	return (true);
}
