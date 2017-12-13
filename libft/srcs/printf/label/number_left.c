/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		s_alt(t_printf *t)
{
	if (t->flags.alt && t->flags.base == 16)
	{
		add_char(t, L'0');
		add_char(t, t->flags.spec);
		t->flags.width -= 2;
	}
	if (t->flags.number.word != 0 && t->flags.alt
		&& t->flags.base == 8)
	{
		add_char(t, '0');
		t->flags.width -= 1;
	}
}

static void		s_flags(t_printf *t)
{
	if (t->flags.is_negative && t->flags.base == 10)
	{
		add_char(t, '-');
		t->flags.width -= 1;
	}
	else if (t->flags.showsign && t->flags.base == 10)
	{
		add_char(t, '+');
		t->flags.width -= 1;
	}
	else if (t->flags.space && t->flags.base == 10)
	{
		add_char(t, ' ');
		t->flags.width -= 1;
	}
}

void			number_left(t_printf *t)
{
	int		temp;

	s_flags(t);
	s_alt(t);
	t->flags.width -= ft_strlen(t->work_buffer)
		+ t->flags.prec;
	if (t->flags.prec > 0)
	{
		temp = t->flags.width;
		t->flags.width = t->flags.prec;
		if (t->flags.number.word != 0 && t->flags.alt
			&& t->flags.base == 8)
		{
			t->flags.width -= 1;
			temp += 1;
		}
		fill_character(t, '0');
		t->flags.width = temp;
	}
	add_string(t, t->work_buffer);
	fill_character(t, ' ');
}
