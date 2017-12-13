/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 00:24:30 by jguyet            #+#    #+#             */
/*   Updated: 2015/12/03 00:31:58 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putlst(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putstr((char*)lst->content);
		lst = lst->next;
	}
}