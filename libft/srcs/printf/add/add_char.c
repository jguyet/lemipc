/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static void		s_new_buffer(t_printf *t, unsigned char c)
{
	unsigned int	len;
	char			*tmp;

	len = 2;
	if (t->buffer != NULL)
		len = t->len + 1;
	t->buffer_size = len + BUFF_SIZE;
	if ((tmp = ft_strnew(t->buffer_size)) == NULL)
		return ;
	if (t->buffer)
	{
		ft_memcpy(tmp, t->buffer, t->len);
		tmp[len - 1] = c;
		++t->len;
	}
	else
	{
		tmp[0] = c;
		++t->len;
	}
	ft_strdel(&t->buffer);
	t->buffer = tmp;
}

void			add_char(t_printf *t, unsigned char c)
{
	unsigned int	len;

	len = 2;
	if (t->buffer != NULL)
		len = t->len + 1;
	if (len > t->buffer_size)
		return (s_new_buffer(t, c));
	if (t->buffer)
	{
		t->buffer[len - 1] = c;
		++t->len;
	}
	else
		return (s_new_buffer(t, c));
}
