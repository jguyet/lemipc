/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	conversion_big_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'F';
	t->flags.number.longdouble = arg_get_double(t);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	number(t);
}

void	conversion_f(t_printf *t)
{
	t->flags.base = 10;
	t->flags.spec = 'f';
	if (t->flags.is_long)
		return ((void)conversion_big_f(t));
	else
		t->flags.number.longdouble = arg_get_double(t);
	if (t->flags.number.longdouble < 0)
	{
		t->flags.number.longdouble =
			t->flags.number.longdouble * -1;
		t->flags.is_negative = true;
	}
	number(t);
}
