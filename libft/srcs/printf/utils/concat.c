/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concat2(char *s1, int len1, char *s2, int len2)
{
	char	*tmp;

	if ((tmp = ft_strnew(len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, len1);
	ft_memcpy(tmp + len1, s2, len2);
	ft_strdel(&s1);
	return (tmp);
}

char	*concat(char *s1, int *len1, char *s2, int len2)
{
	char	*tmp;

	if ((tmp = ft_strnew(*len1 + len2)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s1, *len1);
	ft_memcpy(tmp + *len1, s2, len2);
	ft_strdel(&s1);
	*len1 += len2;
	return (tmp);
}
