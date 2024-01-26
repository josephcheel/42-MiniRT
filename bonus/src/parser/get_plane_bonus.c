/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_geom	*get_plane(char *line, t_field *field)
{
	t_geom	*pln;
	char	**content;

	content = ft_split(line, ' ');
	pln = malloc(sizeof(t_geom));
	pln->type = PLANE;
	pln->vp.pt = add_vec3(content[1]);
	pln->vp.v = conv_v_unit(add_vec3(content[2]));
	pln->color = add_color(content[3]);
	pln->sense = 1;
	pln->next = NULL;
	pln->axis.pos = pln->vp.pt;
	pln->axis.vx = pln->vp.v;
	pln->axis.vy = conv_v_unit(prod_vectorial(create_vect(0, 0, 1),
			pln->axis.vx));
	pln->axis.vz = conv_v_unit(prod_vectorial(pln->axis.vx, pln->axis.vy));
	pln->bumpmap.is_bumpmap = false;
	if (ft_array_size(content) == 5)
		pln->bumpmap = get_bumpmap(content[4], field);
	ft_array_free(content, ft_array_size(content));
	return (pln);
}
