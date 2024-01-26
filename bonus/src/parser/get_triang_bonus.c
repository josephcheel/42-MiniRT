/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triang_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/26 18:18:53 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

<<<<<<< HEAD
static void	create_axis(t_geom *tri)
{
	t_vec3	pt;

	tri->axis.pos.x = (tri->vp.pt.x + tri->vp.pt.x + tri->vp.pt.x) / 3;
	tri->axis.pos.y = (tri->vp.pt.y + tri->vp.pt.y + tri->vp.pt.y) / 3;
	tri->axis.pos.z = (tri->vp.pt.z + tri->vp.pt.z + tri->vp.pt.z) / 3;
	tri->axis.vx = tri->vp.v;
	tri->axis.vy = conv_v_unit(prod_vectorial(create_vect(0, 0, 1), \
			tri->axis.vx));
	tri->axis.vz = conv_v_unit(prod_vectorial(tri->axis.vx, tri->axis.vy));
}

static void	get_optional_values(t_field *field, t_geom *triang, char **content)
{
	if (ft_array_size(content) == 6)
	{
		if (ft_strcmp(content[5], "NO_CHECKBOARD") == 0)
			triang->is_chckbd = false;
		else
			triang->bumpmap = get_bumpmap(content[5], field);
	}
	if (ft_array_size(content) == 7)
	{
		if (ft_strcmp(content[6], "NO_CHECKBOARD") == 0)
			triang->is_chckbd = false;
		else
			triang->bumpmap = get_bumpmap(content[6], field);
	}
}

t_geom	*get_triang(char *line, t_field *field)
{
	t_geom	*triang;
	char	**content;
	t_vec3	aux[2];

	content = ft_split(line, ' ');
	triang = malloc(sizeof(t_geom));
	triang->type = TRIANGLE;
	triang->vp.pt = add_vec3(content[1]);
	triang->vp1.pt = add_vec3(content[2]);
	triang->vp2.pt = add_vec3(content[3]);
	aux[0] = resta_vector(triang->vp1.pt, triang->vp.pt);
	aux[1] = resta_vector(triang->vp2.pt, triang->vp.pt);
	triang->vp.v = conv_v_unit(prod_vectorial(aux[0], aux[1]));
	triang->color = add_color(content[4]);
	triang->sense = 1;
	triang->next = NULL;
	triang->bumpmap.is_bumpmap = false;
	create_axis(triang);
	triang->is_chckbd = true;
	get_optional_values(field, triang, content);
	ft_array_free(content, ft_array_size(content));
	return (triang);
}
