/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:45:52 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 17:45:55 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

struct s_lem	*newlem(void)
{
	struct s_lem	*new;

	if (!(new = (struct s_lem*)malloc(sizeof(struct s_lem))))
		return (NULL);
	new->team = -1;
	return (new);
}

void			destruct_lem(struct s_lem *lem)
{
	free(lem);
}
