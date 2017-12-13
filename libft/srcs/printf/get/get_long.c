/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <stdarg.h>

unsigned long			arg_get_ulong(t_printf *t)
{
	return ((unsigned long)va_arg(t->args, unsigned long));
}

long int				arg_get_long_int(t_printf *t)
{
	return ((long int)va_arg(t->args, long int));
}

unsigned long int		arg_get_ulong_int(t_printf *t)
{
	return ((unsigned long int)va_arg(t->args, unsigned long int));
}

long long int			arg_get_long_long_int(t_printf *t)
{
	return ((long long int)va_arg(t->args, long long int));
}

unsigned long long int	arg_get_ulong_long_int(t_printf *t)
{
	return ((unsigned long long int)va_arg(t->args,
				unsigned long long int));
}
