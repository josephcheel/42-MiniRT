/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/26 18:31:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_optional_values(t_field *field, t_geom *cylinder, \
		char **content)
{
	if (ft_array_size(content) == 7)
	{
		if (ft_strcmp(content[6], "NO_CHECKBOARD") == 0)
			cylinder->is_chckbd = false;
		else
			cylinder->bumpmap = get_bumpmap(content[6], field);
	}
	if (ft_array_size(content) == 8)
	{
		if (ft_strcmp(content[7], "NO_CHECKBOARD") == 0)
			cylinder->is_chckbd = false;
		else
			cylinder->bumpmap = get_bumpmap(content[7], field);
	}
}

t_geom	*get_cylinder(char *line, t_field *field)
{
	t_geom	*cylinder;
	char	**content;

	content = ft_split(line, ' ');
	cylinder = malloc(sizeof(t_geom));
	cylinder->type = CYLINDER;
	cylinder->vp.pt = add_vec3(content[1]);
	cylinder->vp.v = conv_v_unit(add_vec3(content[2]));
	cylinder->r = ft_atof(content[3]) / 2;
	cylinder->height = ft_atof(content[4]);
	cylinder->color = add_color(content[5]);
	cylinder->sense = 1;
	cylinder->next = NULL;
	cylinder->bumpmap.is_bumpmap = false;
	cylinder->is_chckbd = true;
	get_optional_values(field, cylinder, content);
	ft_array_free(content, ft_array_size(content));
	return (cylinder);
}
