/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_pixel_vp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

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
/// @param field variable that contains all information for the visualization
/// @param in Current pixel point
/// @param lim Max pixels in screen
void	def_pixel_vp(t_field *field, t_indexes in, t_indexes lim)
{
	t_vec_pos	*pixel;

	pixel = &field->camera.field_vp[in.i + in.j * (lim.i)];
	pixel->pt = pix_vec(in, lim, field->camera.center);
	if (field->camera.fov == 0)
		pixel->v = field->camera.center.vx;
	else
		pixel->v = conv_v_unit(resta_vector(pixel->pt, field->camera.observer));
	pixel->c = field->ambient.color;
}
