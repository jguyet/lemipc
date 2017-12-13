/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
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
#include <wchar.h>

char			arg_get_char(t_printf *t)
{
	return ((char)arg_get_int(t));
}

unsigned char	arg_get_uchar(t_printf *t)
{
	return ((unsigned char)arg_get_int(t));
}

wchar_t			arg_get_wchar(t_printf *t)
{
	return ((wchar_t)va_arg(t->args, wchar_t));
}
