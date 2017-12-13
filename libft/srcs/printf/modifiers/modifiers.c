/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <inttypes.h>

static t_bool	s_modifiers_1(t_printf *t, char **s)
{
	if (ft_strnstr(*s, "hh", 2))
	{
		++s;
		t->flags.is_short = false;
		t->flags.is_char = true;
		return (true);
	}
	if (**s == 'h')
	{
		t->flags.is_short = true;
		return (true);
	}
	if (ft_strnstr(*s, "ll", 2))
	{
		++(*s);
		t->flags.is_long_double = true;
		t->flags.is_long = true;
		return (true);
	}
	if (**s == 'l')
	{
		t->flags.is_long = true;
		return (true);
	}
	return (false);
}

static t_bool	s_modifiers_2(t_printf *t, char **s)
{
	if (**s == 'z')
	{
		t->flags.is_long_double =
			sizeof(size_t) > sizeof(unsigned long int);
		t->flags.is_long =
			sizeof(size_t) > sizeof(unsigned int);
		return (true);
	}
	if (**s == 'j')
	{
		t->flags.is_long_double =
			sizeof(intmax_t) > sizeof(unsigned long int);
		t->flags.is_long =
			sizeof(intmax_t) > sizeof(unsigned int);
		return (true);
	}
	if (**s == 'L' || **s == 'q')
	{
		t->flags.is_long_double = true;
		t->flags.is_long = true;
		return (true);
	}
	return (false);
}

t_bool			modifiers(t_printf *t, char **s)
{
	if (s_modifiers_1(t, s))
		return (true);
	if (s_modifiers_2(t, s))
		return (true);
	return (false);
}
