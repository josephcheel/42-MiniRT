/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_bumpmap_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:06:02 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/27 17:52:50 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3 get_distance(t_int_pts *vp_int)
{
	t_vec3	out;

	out = vp_int->pt.pt;
	if (vp_int->geom->type == PLANE || vp_int->geom->type == TRIANGLE)
	{
		out = resta_vector(vp_int->pt.pt, vp_int->geom->vp.pt);
		out = cambio_coord_vect(out, vp_int->ref);
	}
	return out;
}

t_indexes	get_indexes(t_vec3 pos, t_geom *geom)
{
	t_indexes	out;

	// printf ("%d %d\n", 15 % 10, -31 % 500);
	// if ((int)fabs(pos.y) > geom->bumpmap.height)
	out.i = (int)fmod(pos.x, geom->bumpmap.width) / BM_DEFINIT;
	out.j = -(int)fmod(pos.y, geom->bumpmap.height) / BM_DEFINIT;
	if (out.i < 0)
		out.i += geom->bumpmap.width;
	if (out.j < 0)
		out.j += geom->bumpmap.height;
//	printf("posicion i = %f, posicion j = %f\n", pos.x, pos.y);
//	printf("ancho i = %i, ancho j = %i\n", geom->bumpmap.width, geom->bumpmap.height);
//	printf("ind i = %i, ind j = %i\n", out.i, out.j);
//	printf("valor de k = %i\n", out.i + out.j * geom->bumpmap.width);
	
	return (out);
}

void set_pixel_color_bumpmap(t_int_pts *vp_int, t_field *field)
{
	t_vec3		out;
	t_indexes	ind;

	(void)field;
	out = get_distance(vp_int);
	ind = get_indexes(out, vp_int->geom);
	out = vp_int->geom->bumpmap.normal_map[ind.i + ind.j * \
										vp_int->geom->bumpmap.width];
	vp_int->pt.v = cambio_coord_vect(out, mat_inversa(vp_int->ref));
	return ;
}
