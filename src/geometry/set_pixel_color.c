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

static t_color	apply_fact(t_color c, double *f, t_color clm)
{
	t_color	out;

	out.r = (int)(c.r * f[0] + c.r * f[1] + clm.r * f[2]);
	if (out.r < 0)
		out.r = 0;
	else if (out.r > 255)
		out.r = 255;
	out.g = (int)(c.g * f[0] + c.g * f[1] + clm.g * f[2]);
	if (out.g < 0)
		out.g = 0;
	else if (out.g > 255)
		out.g = 255;
	out.b = (int)(c.b * f[0] + c.b * f[1] + clm.b * f[2]);
	if (out.b < 0)
		out.b = 0;
	else if (out.b > 255)
		out.b = 255;
	return (out);
}

static bool	is_behind_srf(t_int_pts vp, t_vec_pos vl_pt, t_geom *geo)
{
	double		dist[3];
	t_geom		*ptr;
	t_vec_pos	*out;
	t_vec3		aux;

	aux = resta_vector(vp.pt.pt, vl_pt.pt);
	dist[0] = modulo_vector(aux);
	dist[1] = LONG_MAX;
	dist[2] = LONG_MAX;
	ptr = geo;
	while (ptr)
	{
		if (ptr != vp.geom)
		{
			out = get_int_pt(&vl_pt, ptr);
			if (out != NULL)
			{
				aux = resta_vector(vl_pt.pt, out[0].pt);
				dist[1] = modulo_vector(aux);
				if (prod_escalar(aux, vl_pt.v) < 0)
					dist[1] = LONG_MAX;
				aux = resta_vector(vl_pt.pt, out[1].pt);
				dist[2] = modulo_vector(aux);
				if (prod_escalar(aux, vl_pt.v) < 0)
					dist[2] = LONG_MAX;
			}
			if (dist[0] > dist[1] || dist[0] > dist[2])
				return (true);
		}
		ptr = ptr->next;
	}
	return (false);
}

static double	get_difuse(t_vec_pos vp, t_vec_pos vl_pt)
{
	double	aux;

	aux = prod_escalar(vp.v, vl_pt.v);
	return (aux);
}

static double	get_specular(t_vec_pos vp, t_vec_pos vl_pt, t_vec_pos pixl)
{
	double	aux;
	t_vec3	out;

	aux = 2 * prod_escalar(vp.v, vl_pt.v);
	out = resta_vector(prod_cte_vector(aux, vp.v), vl_pt.v);
	aux = prod_escalar(out, pixl.v);
	aux = aux * aux * aux * aux;
	return (aux);
}

/// @brief Calculates the color of the pixel depending of the light position
/// @brief The function also takes into account if there is any surface that
/// @brief is in between the point and the light (Shadow from other element)
/// @param vp
/// @param field
/// @return Returns the color of the pixel.
t_color	set_pixel_color(t_int_pts vp, t_field *field, t_vec_pos pixl)
{
	t_vec_pos	v_luz_pt;
	double		fact[3];

	v_luz_pt.pt = field->light->pos;
	v_luz_pt.v = conv_v_unit(resta_vector(v_luz_pt.pt, vp.pt.pt));
	v_luz_pt.c = field->light->color;
	if (is_behind_srf(vp, v_luz_pt, field->geom))
	{
		fact[0] = field->ambient.ratio;
		fact[1] = 0;
		fact[2] = 0;
	}
	else
	{
		fact[0] = field->ambient.ratio;
		fact[1] = field->light->ratio * get_difuse(vp.pt, v_luz_pt);
		fact[2] = field->light->ratio * get_specular(vp.pt, v_luz_pt, pixl);
	}
	vp.pt.c = apply_fact(vp.pt.c, fact, v_luz_pt.c);
	return (vp.pt.c);
}
