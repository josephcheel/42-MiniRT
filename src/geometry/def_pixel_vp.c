/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_vec3	pix_vec(t_indexes in, t_indexes lim, t_axis axis)
{
	t_vec3	tmp[3];
	t_vec3	aux;

	tmp[1] = prod_cte_vector((lim.i / 2 - in.i) * PIXEL, \
				axis.vx);
	tmp[2] = prod_cte_vector((lim.j / 2 - in.j) * PIXEL, \
				axis.vy);
	tmp[0] = suma_vector(tmp[1], tmp[2]);
	aux = suma_vector(tmp[0], axis.pos);
	return (aux);
}

void	def_pixel_vp(t_field *field, t_indexes in, t_indexes lim)
{
	field->camera.field_vp[in.i + in.j * (lim.i)].pt = \
		pix_vec(in, lim, field->camera.center);
	field->camera.field_vp[in.i + in.j * (lim.i)].v = \
		resta_vector(field->camera.field_vp[in.i + in.j * lim.i].pt, \
				field->camera.observer);
	field->camera.field_vp[in.i + in.j * (lim.i)].v = \
		conv_v_unit(field->camera.field_vp[in.i + in.j * lim.i].v);
	field->camera.field_vp[in.i + in.j * (lim.i)].c = field->ambient.color;
}
