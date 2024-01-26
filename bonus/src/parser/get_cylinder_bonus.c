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
	t_geom	*cyl;
	char	**content;

	content = ft_split(line, ' ');
	cyl = malloc(sizeof(t_geom));
	cyl->type = CYLINDER;
	cyl->vp.pt = add_vec3(content[1]);
	cyl->vp.v = conv_v_unit(add_vec3(content[2]));
	cyl->r = ft_atof(content[3]) / 2;
	cyl->height = ft_atof(content[4]);
	cyl->color = add_color(content[5]);
	cyl->sense = 1;
	cyl->next = NULL;
	cyl->axis.pos = cyl->vp.pt;
	cyl->axis.vx = cyl->vp.v;
	cyl->axis.vy = conv_v_unit(prod_vectorial(create_vect(0, 0, 1),
			cyl->axis.vx));
	cyl->axis.vz = conv_v_unit(prod_vectorial(cyl->axis.vx, cyl->axis.vy));
	cyl->bumpmap.is_bumpmap = false;
	cyl->is_chckbd = true;
	get_optional_values(field, cyl, content);
	ft_array_free(content, ft_array_size(content));
	return (cyl);
}
