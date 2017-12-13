/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		s_trunc(char **s, int length)
{
	int		size;
	int		index;
	char	*string;

	size = (length < 0) ? -length : length;
	string = ft_strnew(size);
	if (*s == NULL)
		return ;
	index = 0;
	while ((*s)[index] && index < size)
	{
		string[index] = (*s)[index];
		++index;
	}
	ft_strdel(s);
	*s = string;
}

void			to_string(t_printf *t, char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (t->flags.prec != -1)
	{
		s_trunc(&s, t->flags.prec);
		len = ft_strlen(s);
	}
	if ((t->flags.width -= len) < 0)
	{
		add_string(t, s);
		return ;
	}
	if (t->flags.left == false)
		fill_character(t, t->flags.pad);
	add_string(t, s);
	if (t->flags.left)
		fill_character(t, t->flags.pad);
}

void			to_char(t_printf *t, char c)
{
	if ((t->flags.width -= 1) < 0)
		return (add_char(t, c));
	if (t->flags.left == false)
		fill_character(t, t->flags.pad);
	add_char(t, c);
	if (t->flags.left)
		fill_character(t, t->flags.pad);
}

void			to_wchar(t_printf *t, wchar_t c)
{
	if ((t->flags.width -= 1) < 0)
		return (add_wchar(t, c));
	if (t->flags.left == false)
		fill_character(t, t->flags.pad);
	add_wchar(t, c);
	if (t->flags.left)
		fill_character(t, t->flags.pad);
}
