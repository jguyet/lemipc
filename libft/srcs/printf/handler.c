/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <stdlib.h>

static t_bool	s_check_conversion(t_printf *t, char **s)
{
	int		i;
	char	*flags;

	i = 0;
	flags = ft_strdup("%sSpdDioOuUxXcCbBfF");
	while (flags && flags[i])
	{
		if (**s == flags[i])
			break ;
		i++;
	}
	if (flags[i] == '\0')
	{
		ft_strdel(&flags);
		return (false);
	}
	t->ptr_funcs[i](t);
	ft_strdel(&flags);
	return (true);
}

static void		s_check_action(t_printf *t, char **s)
{
	char	sc[2];

	++(*s);
	while ((flags(t, s) || modifiers(t, s)))
		++(*s);
	if (**s)
	{
		if (s_check_conversion(t, s) == false)
		{
			sc[0] = **s;
			sc[1] = '\0';
			t->flags.prec = -1;
			to_string(t, ft_strdup(sc));
		}
	}
	else
		--(*s);
}

void			handle_printf_flags(t_printf *t, char *s)
{
	while (*s)
	{
		ini_flags(t);
		if (*s == '%')
		{
			s_check_action(t, &s);
			++s;
		}
		else
		{
			add_char(t, *s);
			++s;
		}
	}
}
