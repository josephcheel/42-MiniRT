/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/26 18:18:46 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_optional_values(t_field *field, t_geom *plane, char **content)
{
	if (ft_array_size(content) == 5)
	{
		if (ft_strcmp(content[4], "NO_CHECKBOARD") == 0)
			plane->is_chckbd = false;
		else
			plane->bumpmap = get_bumpmap(content[4], field);
	}
	if (ft_array_size(content) == 6)
	{
		if (ft_strcmp(content[5], "NO_CHECKBOARD") == 0)
			plane->is_chckbd = false;
		else
			plane->bumpmap = get_bumpmap(content[5], field);
	}
}

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
	plane->is_chckbd = true;
	get_optional_values(field, plane, content);
	ft_array_free(content, ft_array_size(content));
	return (pln);
}
