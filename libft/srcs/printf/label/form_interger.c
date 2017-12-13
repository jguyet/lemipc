/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_interger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	form_interger(t_printf *t)
{
	long long int	signed_number;

	if (t->flags.is_long)
		signed_number = arg_get_long_int(t);
	else if (t->flags.is_char)
		signed_number = (signed char)arg_get_uint(t);
	else if (!t->flags.is_short)
		signed_number = arg_get_int(t);
	else
		signed_number = (short int)arg_get_uint(t);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
		t->flags.number.longlong = signed_number * -1;
	else
		t->flags.number.longlong = signed_number;
	number(t);
}
