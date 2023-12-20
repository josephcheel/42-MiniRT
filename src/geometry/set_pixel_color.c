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

t_color	set_pixel_color(t_vec_pos vp, t_vec3 vl)
{
	t_vec_pos	v_luz_pt;
	double		shadow_fact;

	v_luz_pt.pt = vl;
	v_luz_pt.v = conv_v_unit(resta_vector(vp.pt, vl));
	shadow_fact = prod_escalar (vp.v, v_luz_pt.v);
	shadow_fact = (1 - shadow_fact) / 2;
	vp.c = apply_fact (vp.c, shadow_fact);
	return (vp.c);
}
