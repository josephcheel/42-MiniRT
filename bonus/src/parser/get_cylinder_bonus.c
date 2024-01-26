/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

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
	cyl->axis.vy = conv_v_unit(prod_vectorial(create_vect(0, 0, 1), \
			cyl->axis.vx));
	cyl->axis.vz= conv_v_unit(prod_vectorial(cyl->axis.vx, cyl->axis.vy));
	cyl->bumpmap.is_bumpmap = false;
	if (ft_array_size(content) == 7)
		cyl->bumpmap = get_bumpmap(content[6], field);
	ft_array_free(content, ft_array_size(content));
	return (cyl);
}
