/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pict_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_vec_pos	init_vp(void)
{
	t_vec_pos	vp;

	vp.v = create_vect(0, 0, 0);
	vp.pt = create_vect(LONG_MAX, LONG_MAX, LONG_MAX);
	return (vp);
}

bool	is_new_closer(t_vec_pos new, t_field *field)
{
	double observer_point;
	double observer_camera;
	t_vec3 temp;

	temp = resta_vector( new.pt, field->camera.observer);
	observer_point = sqrt(prod_escalar(temp, temp));
	observer_camera = (field->mlx.size_x - FRAME) * PIXEL / 2 / tan(field->camera.fov / 2);
	if (observer_point <= observer_camera)
		return (true);
	return (false);
}

static t_vec_pos	get_min_vect(t_vec_pos cur, t_vec_pos *new, t_geom *geom, t_field *field)
{
	t_vec_pos	out;
	double		long_cur;
	double		long_new;

	out = cur;
	if (!new)
		return (cur);
	long_cur = modulo_vector(cur.pt);
	long_new = modulo_vector(new[0].pt);
	if (long_cur > long_new)
	{
		if (is_new_closer(new[0], field))
			return (cur);
		out = new[0];
		out.c = geom->color;
	}
	if (geom->type != PLANE)
	{
		long_cur = modulo_vector(out.pt);
		long_new = modulo_vector(new[1].pt);
		if (long_cur > long_new)
		{
			if (is_new_closer(new[1], field))
				return (cur);
			out = new[1];
			out.c = geom->color;
		}
	}
	return (out);
}

t_vec_pos	get_int_pt(t_vec_pos vps, t_geom *geom, t_field *field)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_vec_pos	vp_int;

	ptr = geom;
	vp_int = init_vp();
	while (ptr)
	{
		if (ptr->type == SPHERE)
			out = int_vect_esfera(vps, ptr->vp.pt, ptr->r);
		else if (ptr->type == CYLINDER)
			out = int_vect_cilind(vps, ptr->vp, ptr->r);
		else if (ptr->type == PLANE)
			out = int_vect_plano(vps, ptr->vp);
		if (out != NULL)
			vp_int = get_min_vect(vp_int, out, ptr, field);
		free(out);
		ptr = ptr->next;
	}
	return (vp_int);
}
