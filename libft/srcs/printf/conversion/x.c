/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	conversion_big_x(t_printf *t)
{
	t->flags.base = 16;
	t->flags.spec = 'X';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = arg_get_ulong_int(t);
	else if (t->flags.is_char)
		t->flags.number.longlong = arg_get_uchar(t);
	else
		t->flags.number.longlong = arg_get_uint(t);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	number(t);
}

void	conversion_x(t_printf *t)
{
	t->flags.base = 16;
	t->flags.spec = 'x';
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = arg_get_ulong_int(t);
	else if (t->flags.is_char)
		t->flags.number.longlong = arg_get_uchar(t);
	else
		t->flags.number.longlong = arg_get_uint(t);
	if (t->flags.number.longlong == 0)
		t->flags.alt = false;
	number(t);
}
