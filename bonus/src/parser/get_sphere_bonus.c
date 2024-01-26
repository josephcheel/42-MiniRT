/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_geom	*get_sphere(char *line, t_field *field)
{
	t_geom	*sph;
	char	**content;

	content = ft_split(line, ' ');
	sph = malloc(sizeof(t_geom));
	sph->type = SPHERE;
	sph->vp.pt = add_vec3(content[1]);
	sph->vp.v = create_vect(0, 0, 0);
	sph->r = ft_atof(content[2]) / 2;
	sph->color = add_color(content[3]);
	sph->sense = 1;
	sph->next = NULL;
	sph->bumpmap.is_bumpmap = false;
	sph->axis.pos = sph->vp.pt;
	sph->axis.vx = create_vect(1, 0, 0);
	sph->axis.vy = create_vect(0, 1, 0);
	sph->axis.vz = create_vect(0, 0, 1);
	if (ft_array_size(content) == 5)
		sph->bumpmap = get_bumpmap(content[4], field);
	ft_array_free(content, ft_array_size(content));
	return (sph);
}
