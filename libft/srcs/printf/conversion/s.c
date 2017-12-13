/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:32:57 by jguyet            #+#    #+#             */
/*   Updated: 2017/03/29 06:32:59 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

void	conversion_big_s(t_printf *t)
{
	wchar_t		*sw;

	sw = arg_get_wstring(t);
	if (sw == NULL && t->flags.alt == true)
		to_string(t, ft_strdup(""));
	else if (sw == NULL)
		to_string(t, ft_strdup("(null)"));
	else
		to_string(t, wstr_to_str(t, sw));
}

void	conversion_s(t_printf *t)
{
	char	*s;

	if (t->flags.is_long && !t->flags.is_long_double)
		return (conversion_big_s(t));
	s = arg_get_string(t);
	if (s == NULL && t->flags.alt == true)
		to_string(t, ft_strdup(""));
	else if (s == NULL)
		to_string(t, ft_strdup("(null)"));
	else
		to_string(t, ft_strdup(s));
}
