/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/18 18:32:25 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static double	calculate_behind_pts(t_int_pts vp, t_vec_pos vl_pt, t_geom *ptr)
{
	t_vec3		aux;
	double		dist[3];
	t_vec_pos	*out;

	aux = resta_vector(vl_pt.pt, vp.pt.pt);
	dist[0] = modulo_vector(aux);
	dist[1] = LONG_MAX;
	dist[2] = LONG_MAX;
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
	free(out);
	if (dist[0] > dist[1] || dist[0] > dist[2])
		return (true);
	return (false);
}

static bool	is_behind_srf(t_int_pts vp, t_vec_pos vl_pt, t_geom *geo)
{
	t_geom	*ptr;

	ptr = geo;
	while (ptr)
	{
		if (ptr != vp.geom)
		{
			if (calculate_behind_pts(vp, vl_pt, ptr))
				return (true);
		}
		ptr = ptr->next;
	}
	return (false);
}

static double	get_difuse(t_vec_pos vp, t_vec_pos vl_pt, double amb_rate)
{
	double	aux;

	(void)amb_rate;
	aux = prod_escalar(vp.v, vl_pt.v);
	if (aux < 0)
		aux = 0;
	return (aux);
}

static double	get_specular(t_vec_pos vp, t_vec_pos vl_pt, t_vec_pos pixl)
{
	double	aux;
	t_vec3	out;

	aux = 2 * prod_escalar(vp.v, vl_pt.v);
	if (aux < 0)
		return (0);
	out = resta_vector(prod_cte_vector(aux, vp.v), vl_pt.v);
	aux = prod_escalar(out, pixl.v);
	if (aux > 0)
		return (0);
	aux = pow(aux, 32);
	return (aux);
}

/*
@brief Calculates the color of the pixel depending of the light position
@brief The function also takes into account if there is any surface that
@brief is in between the point and the light (Shadow from other element)
@param vp
@param field
@return Returns the color of the pixel.
*/
t_color	set_pixel_color(t_int_pts vp, t_field *field, t_vec_pos pixl)
{
	t_vec_pos	v_luz_pt;
	t_color		out[5];
	double		aux;
	t_light		*lght;

	out[3].r = 0;
	out[3].g = 0;
	out[3].b = 0;
	out[3].a = 0;
	rgb_to_hsl(&out[3]);
	if (vp.pt.pt.x == LONG_MAX && vp.pt.pt.z == LONG_MAX \
		&& vp.pt.pt.z == LONG_MAX)
		out[4] = field->ambient.color;
	else
	{
		lght = field->light;
		while (lght)
		{
			v_luz_pt.pt = lght->pos;
			v_luz_pt.v = conv_v_unit(resta_vector(v_luz_pt.pt, vp.pt.pt));
			v_luz_pt.c = lght->color;
			if (is_behind_srf(vp, v_luz_pt, field->geom))
			{
				out[3] = mult_color(v_luz_pt.c, field->ambient.ratio);
			}
			else
			{
				out[0] = mult_color(v_luz_pt.c, field->ambient.ratio);
				aux = get_difuse(vp.pt, v_luz_pt, field->ambient.ratio);
				out[1] = mult_color(v_luz_pt.c, aux);
				out[2] = mix_color(out[0], out[1]);
				aux = get_specular(vp.pt, v_luz_pt, pixl);
				out[1] = mult_color(v_luz_pt.c, aux);
				out[2] = mix_color(out[1], out [2]);
				out[3] = mix_color(out[3], out[2]);
			}
			lght = lght->next;
		}
		out[4] = prod_color(out[3], vp.pt.c);
		out[4] = limit_color(out[4]);
		hsl_to_rgb(&out[3]);
	}
	return (out[4]);
}
