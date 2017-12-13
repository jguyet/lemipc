/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	conversion_big_d(t_printf *t)
{
	long long int	signed_number;

	t->flags.base = 10;
	signed_number = arg_get_long_int(t);
	t->flags.is_negative = signed_number < 0;
	if (t->flags.is_negative)
	{
		t->flags.number.longlong = signed_number * -1;
	}
	else
	{
		t->flags.number.longlong = signed_number;
	}
	number(t);
}
