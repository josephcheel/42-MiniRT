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
	if (ft_array_size(content) == 7)
		cylinder->bumpmap = get_bumpmap(content[6], field);
	ft_array_free(content, ft_array_size(content));
	return (cylinder);
}
