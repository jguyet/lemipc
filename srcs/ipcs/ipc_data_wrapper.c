/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ipc_data_wrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:54:03 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/13 15:54:05 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

struct s_bytebuffer *newbytebuffer(void *ptr, int size)
{
	struct s_bytebuffer *new;

	if (!(new = (struct s_bytebuffer*)malloc(sizeof(struct s_bytebuffer))))
		return (NULL);
	new->data = ptr;
	new->position = 0;
	new->size = size;
	new->write_int = write_int;
	new->write_short = write_short;
	new->write_char = write_char;
	new->write_string = write_string;
	new->read_int = read_int;
	new->read_short = read_short;
	new->read_char = read_char;
	new->read_string = read_string;
	return (new);
}

void			destruct_bytebuffer(struct s_bytebuffer *buffer)
{
	free(buffer);
}

void			write_int(struct s_bytebuffer *buffer, int n)
{
	buffer->data[buffer->position++] = ((n >> 24) & 0xFF);
	buffer->data[buffer->position++] = ((n >> 16) & 0xFF);
	buffer->data[buffer->position++] = ((n >> 8) & 0xFF);
	buffer->data[buffer->position++] = (n & 0xFF);
}

void			write_short(struct s_bytebuffer *buffer, short n)
{
	buffer->data[buffer->position++] = ((n >> 8) & 0xFF);
	buffer->data[buffer->position++] = (n & 0xFF);
}

void			write_char(struct s_bytebuffer *buffer, char c)
{
	buffer->data[buffer->position++] = (c & 0xFF);
	buffer->data += 1;
	buffer->position += 1;
}

void			write_string(struct s_bytebuffer *buffer, char *s)
{
	size_t	length;

	length = ft_strlen(s);
	write_int(buffer, length);
	ft_memcpy(buffer->data + buffer->position, s, length);
	buffer->position += length;
}

void			write_memory(struct s_bytebuffer *buffer, void *m, size_t size)
{
	ft_memcpy(buffer->data, m, size);
	buffer->position += size;
}

int				read_int(struct s_bytebuffer *buffer)
{
	return (((buffer->data[buffer->position++] & 0xFF) << 24)\
			+ ((buffer->data[buffer->position++] & 0xFF) << 16)\
			+ ((buffer->data[buffer->position++] & 0xFF) << 8)\
			+ ((buffer->data[buffer->position++] & 0xFF)));
}

short			read_short(struct s_bytebuffer *buffer)
{
	return (((buffer->data[buffer->position++] & 0xFF) << 8)\
			+ (buffer->data[buffer->position++] & 0xFF));
}

char			read_char(struct s_bytebuffer *buffer)
{
	return (buffer->data[buffer->position++] & 0xFF);
}

char			*read_string(struct s_bytebuffer *buffer)
{
	char	*str;
	int		length;

	length = read_int(buffer);
	str = ft_strnew(length);
	ft_memcpy(str, buffer->data + buffer->position, length);
	buffer->position += length;
	return (str);
}
