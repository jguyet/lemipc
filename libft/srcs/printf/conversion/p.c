/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	conversion_p(t_printf *t)
{
	const void	*ptr;

	ptr = arg_get_void(t);
	if (t->flags.prec == 0 && ptr == NULL)
	{
		t->flags.prec = -1;
		t->flags.pad = ' ';
		to_string(t, ft_strdup("0x"));
		return ;
	}
	t->flags.base = 16;
	t->flags.number.word = (unsigned long int)ptr;
	t->flags.is_negative = false;
	t->flags.alt = true;
	t->flags.spec = 'x';
	number(t);
}
