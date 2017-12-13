/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
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
	}
	else if (t->flags.showsign && t->flags.base == 10)
	{
		add_char(t, '+');
	}
	else if (t->flags.space && t->flags.base == 10)
	{
		add_char(t, ' ');
	}
}

static void		s_if_flags(t_printf *t)
{
	if (t->flags.is_negative && t->flags.base == 10)
		t->flags.width -= 1;
	else if (t->flags.showsign && t->flags.base == 10)
		t->flags.width -= 1;
	else if (t->flags.space && t->flags.base == 10)
		t->flags.width -= 1;
	if (t->flags.alt && t->flags.base == 16)
		t->flags.width -= 2;
	if (t->flags.prec <= (int)ft_strlen(t->work_buffer)
		&& t->flags.alt && t->flags.base == 8)
		t->flags.width -= 1;
}

static void		s_not_left(t_printf *t)
{
	t->flags.width -= ft_strlen(t->work_buffer)
		+ t->flags.prec;
	s_if_flags(t);
	if (t->flags.pad == ' ')
	{
		fill_character(t, ' ');
		t->flags.width = 0;
	}
	s_flags(t);
	s_alt(t);
	t->flags.width += t->flags.prec;
	fill_character(t, '0');
	add_string(t, t->work_buffer);
}

void			number(t_printf *t)
{
	if (t->flags.prec < 0
			&& ft_tolower(t->flags.spec) != 'f')
		t->flags.prec = 1;
	else if (ft_tolower(t->flags.spec) != 'f')
		t->flags.pad = ' ';
	if (t->flags.prec == 0 && t->flags.number.word == 0)
	{
		if ((t->flags.base == 8 && t->flags.alt)
			|| ft_tolower(t->flags.spec) == 'f'
			|| t->flags.spec == 'b')
			number_type(t);
	}
	else
		number_type(t);
	if (ft_tolower(t->flags.spec) == 'f' && t->flags.alt
		&& t->flags.prec == 0)
		t->work_buffer = concat2(t->work_buffer,
				ft_strlen(t->work_buffer), ".", 1);
	t->flags.prec = ft_max(0, t->flags.prec -
			ft_strlen(t->work_buffer));
	if (t->flags.left == false)
		s_not_left(t);
	else
		number_left(t);
}
