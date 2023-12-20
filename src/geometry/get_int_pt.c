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

static t_vec_pos	init_vp(t_color c)
{
	t_vec_pos	vp;

	vp.v = create_vect(0, 0, 0);
	vp.pt = create_vect(LONG_MAX, LONG_MAX, LONG_MAX);
	vp.c = c;
	return (vp);
}

bool	is_new_closer(t_vec_pos new, t_vec_pos vps)
{
	t_vec3	temp;

	temp = conv_v_unit(resta_vector(new.pt, vps.pt));
	if (prod_escalar(temp, vps.v) > 0)
		return (false);
	return (true);
}

static t_vec_pos	get_min_vect(t_vec_pos cur, t_vec_pos *new, \
						t_geom *geom, t_vec_pos vps)
{
	t_vec_pos	out;
	t_vec_pos	aux;
	double		long_cur;
	double		long_new;

	out = cur;
	aux = new[0];
	if (!new)
		return (cur);
	long_cur = modulo_vector(cur.pt);
	long_new = modulo_vector(new[0].pt);
	if (geom->type != PLANE && modulo_vector(new[1].pt) < long_new)
	{
		aux = new[1];
		long_new = modulo_vector(new[1].pt);
	}
	if (long_cur > long_new && !is_new_closer(aux, vps))
	{
		out = aux;
		out.c = geom->color;
	}
	return (out);
}

void	get_int_pt(int pixel, t_field *field)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_vec_pos	*vp_int;
	t_vec_pos	*vps;

	ptr = field->geom;
	vps = &field->camera.field_vp[pixel];
	vp_int = &field->camera.int_vp[pixel];
	*vp_int = init_vp(vps->c);
	while (ptr)
	{
		if (ptr->type == SPHERE)
			out = int_vect_esfera(*vps, ptr->vp.pt, ptr->r);
		else if (ptr->type == CYLINDER)
			out = int_vect_cilind(*vps, ptr->vp, ptr->r);
		else if (ptr->type == PLANE)
			out = int_vect_plano(*vps, ptr->vp);
		if (out != NULL)
		{
			*vp_int = get_min_vect(*vp_int, out, ptr, *vps);
			vp_int->c = set_pixel_color(*vp_int, field->light->pos);
		}
		free(out);
		ptr = ptr->next;
	}
}
