/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

#include <stdlib.h>

int				ft_printf(const char *format, ...)
{
	int			len;
	t_printf	*t;

	t = ini_printf();
	va_start(t->args, format);
	handle_printf_flags(t, (char *)format);
	va_end(t->args);
	t->buffer = modif_colors(t->buffer);
	write(1, t->buffer, t->len);
	ft_strdel(&t->buffer);
	len = t->len;
	free(t);
	return (len);
}

int				ft_fprintf(int fd, const char *format, ...)
{
	int			len;
	t_printf	*t;

	t = ini_printf();
	va_start(t->args, format);
	handle_printf_flags(t, (char *)format);
	va_end(t->args);
	t->buffer = modif_colors(t->buffer);
	write(fd, t->buffer, t->len);
	ft_strdel(&t->buffer);
	len = t->len;
	free(t);
	return (len);
}

int				ft_asprintf(char **ptr, const char *format, ...)
{
	int			len;
	t_printf	*t;

	t = ini_printf();
	va_start(t->args, format);
	handle_printf_flags(t, (char *)format);
	va_end(t->args);
	t->buffer = modif_colors(t->buffer);
	*ptr = t->buffer;
	len = t->len;
	free(t);
	return (len);
}

char			*ft_sprintf(const char *format, ...)
{
	t_printf	*t;
	char		*buffer;

	t = ini_printf();
	va_start(t->args, format);
	handle_printf_flags(t, (char *)format);
	va_end(t->args);
	t->buffer = modif_colors(t->buffer);
	buffer = t->buffer;
	free(t);
	return (buffer);
}
