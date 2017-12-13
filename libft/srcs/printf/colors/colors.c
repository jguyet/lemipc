/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 05:18:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/17 05:19:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PRINTF_PROG

#include "printf.h"

static char	*add_color_256(char *string)
{
	char	*name;
	char	*color;
	int		i;

	i = 0;
	while (i < 256)
	{
		name = ft_dstrjoin(ft_dstrjoin("{color", ft_itoa(i), 2), "}", 1);
		color = ft_dstrjoin(ft_dstrjoin("\e[38;05;", ft_itoa(i), 2), "m", 1);
		string = ft_replace(string, name, color);
		ft_strdel(&name);
		ft_strdel(&color);
		i++;
	}
	return (string);
}

char		*modif_colors(char *string)
{
	if (COLOR_ACTIVED == 0)
		return (string);
	if (!ft_strcontains(string, "{") || !ft_strcontains(string, "}"))
		return (string);
	string = ft_replace(string, "{red}", RED);
	string = ft_replace(string, "{reset}", NRM);
	string = ft_replace(string, "{green}", GRN);
	string = ft_replace(string, "{yellow}", YEL);
	string = ft_replace(string, "{blue}", BLU);
	string = ft_replace(string, "{magenta}", MAG);
	string = ft_replace(string, "{cyan}", CYN);
	string = ft_replace(string, "{white}", WHT);
	string = ft_replace(string, "{bold}", BOL);
	string = add_color_256(string);
	return (string);
}
