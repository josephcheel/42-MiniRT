/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_add_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:09:18 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 00:35:46 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static t_color	get_color_from_string(char *colorname)
{
	t_color	color;

	color = add_color("255,0,0");
	if (!ft_strcmp(colorname, "BLACK"))
		color = add_color("0,0,0");
	else if (!ft_strcmp(colorname, "RED"))
		color = add_color("255,0,0");
	else if (!ft_strcmp(colorname, "GREEN"))
		color = add_color("0,255,0");
	else if (!ft_strcmp(colorname, "YELLOW"))
		color = add_color("255,255,0");
	else if (!ft_strcmp(colorname, "BLUE"))
		color = add_color("0,0,255");
	else if (!ft_strcmp(colorname, "MAGENTA"))
		color = add_color("255,0,255");
	else if (!ft_strcmp(colorname, "CYAN"))
		color = add_color("0,255,255");
	else if (!ft_strcmp(colorname, "WHITE"))
		color = add_color("255,255,255");
	return (color);
}

int	get_checkboard(t_field *field, char *line)
{
	char	**content;

	content = ft_split(line, ' ');
	field->chckbd.is_chckbd = true;
	if (ft_isallalpha(content[1]))
		field->chckbd.c1 = get_color_from_string(content[1]);
	else
		field->chckbd.c1 = add_color(content[1]);
	if (ft_isallalpha(content[2]))
		field->chckbd.c2 = get_color_from_string(content[2]);
	else
		field->chckbd.c2 = add_color(content[2]);
	field->chckbd.size = ft_atof(content[3]);
	ft_array_free(content, ft_array_size(content));
	return (true);
}
