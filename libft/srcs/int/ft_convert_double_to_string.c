/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 02:17:00 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/15 02:25:44 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_convert_double_to_string(double n, unsigned int prec)
{
	char		*str;

	str = ft_ftoa(n, prec);
	return (str);
}
