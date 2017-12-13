/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
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

char		*arg_get_string(t_printf *t)
{
	return ((char *)va_arg(t->args, char *));
}

wchar_t		*arg_get_wstring(t_printf *t)
{
	return ((wchar_t *)va_arg(t->args, wchar_t *));
}
