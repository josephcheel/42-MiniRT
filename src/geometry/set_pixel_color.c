/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_color	apply_fact(t_color c, double f)
{
	t_color	out;

	out.r = (int)c.r * f;
	out.g = (int)c.g * f;
	out.b = (int)c.b * f;
	return (out);
}

/*
static double	get_shadow_fact(t_vec_pos vp, t_vec_pos vl_pt, t_geom *geo)
{
	double		aux;
	double		dist[3];
	t_geom		*ptr;
	t_vec_pos	*out;

	ptr = geo;
	aux = -prod_escalar (vp.v, vl_pt.v);
	if (aux <= 0)
		return (0);
	dist[0] = modulo_vector(resta_vector(vp.pt,vl_pt.pt));
	dist[1] = LONG_MAX;
	dist[2] = LONG_MAX;
	while (ptr && aux > 0)
	{	
		out = get_int_pt(&vl_pt, ptr);
		if (out != NULL)
		{	
			dist[1] = modulo_vector(resta_vector(out[0].pt,vl_pt.pt));
			if (prod_escalar(resta_vector(out[0].pt,vl_pt.pt), vl_pt.v) < 0)
				dist[1] = LONG_MAX;
			dist[2] = modulo_vector(resta_vector(out[1].pt,vl_pt.pt));
			if (prod_escalar(resta_vector(out[0].pt,vl_pt.pt), vl_pt.v) < 0)
				dist[1] = LONG_MAX;
		}
		if (dist[0] > dist[1] || dist[0] > dist[2])
			aux = 0;
		ptr = ptr->next;
	}
//	if(aux != 0)
//	{
//		aux = prod_escalar (vp.v, vl_pt.v);
//		aux = (1 - aux) / 2;
//	}
	return (aux);
}
*/
t_color	set_pixel_color(t_vec_pos vp, t_field *field)
{
	t_vec_pos	v_luz_pt;
	double		shadow_fact;

	v_luz_pt.pt = field->light->pos;
	v_luz_pt.v = conv_v_unit(resta_vector(vp.pt, v_luz_pt.pt));
	//shadow_fact = get_shadow_fact(vp, v_luz_pt, field->geom);
	//shadow_fact = (1 - prod_escalar (vp.v, v_luz_pt.v)) / 2;
	shadow_fact = - prod_escalar (vp.v, v_luz_pt.v);
	if (shadow_fact < 0)
		shadow_fact = 0;
	vp.c = apply_fact (vp.c, shadow_fact * field->ambient.ratio);
	return (vp.c);
}
