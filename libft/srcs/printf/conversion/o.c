/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	conversion_big_o(t_printf *t)
{
	long long int	signed_number;

	t->flags.base = 8;
	signed_number = arg_get_ulong_int(t);
	t->flags.number.longlong = signed_number;
	number(t);
}

void	conversion_o(t_printf *t)
{
	t->flags.base = 8;
	t->flags.is_negative = 0;
	t->flags.showsign = 0;
	t->flags.space = 0;
	if (t->flags.is_long)
		t->flags.number.longlong = arg_get_ulong_int(t);
	else if (t->flags.is_char)
		t->flags.number.longlong = (unsigned char)arg_get_uint(t);
	else if (!t->flags.is_short)
		t->flags.number.longlong = arg_get_uint(t);
	else
		t->flags.number.longlong =
			(unsigned short int)arg_get_uint(t);
	number(t);
}
