/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_pixel_vp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/// @brief Calculates the position in space of the i, j picture of the camera.
/// @brief The position depends of the PIXEL dimension which is defined into
/// @brief  the .hfile.
/// @param in
/// @param lim
/// @param axis
/// @return A vector t_vec3 of the position in space ()
static t_vec3	pix_vec(t_indexes in, t_indexes lim, t_axis axis)
{
	t_vec3	tmp[3];
	t_vec3	aux;

	tmp[1] = prod_cte_vector((lim.i / 2 - in.i) * PIXEL, \
				axis.vy);
	tmp[2] = prod_cte_vector((lim.j / 2 - in.j) * PIXEL, \
				axis.vz);
	tmp[0] = suma_vector(tmp[1], tmp[2]);
	aux = suma_vector(tmp[0], axis.pos);
	return (aux);
}

/// @brief creates the field of vectors (position & direction) for every pixel
/// @brief in the camera.
/// @param field
/// @param in
/// @param lim
void	def_pixel_vp(t_field *field, t_indexes in, t_indexes lim)
{
	field->camera.field_vp[in.i + in.j * (lim.i)].pt = \
		pix_vec(in, lim, field->camera.center);
	if (field->camera.fov == 0)
		field->camera.field_vp[in.i + in.j * (lim.i)].v = \
			field->camera.center.vx;
	else
		field->camera.field_vp[in.i + in.j * (lim.i)].v = \
			resta_vector(field->camera.field_vp[in.i + in.j * lim.i].pt, \
				field->camera.observer);
	field->camera.field_vp[in.i + in.j * (lim.i)].v = \
		conv_v_unit(field->camera.field_vp[in.i + in.j * lim.i].v);
	field->camera.field_vp[in.i + in.j * (lim.i)].c = field->ambient.color;
}
