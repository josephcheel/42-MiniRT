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

static bool	is_behind_cam(t_vec_pos new, t_vec_pos vps)
{
	t_vec3	temp;

	temp = conv_v_unit(resta_vector(new.pt, vps.pt));
	if (prod_escalar(temp, vps.v) > 0)
		return (false);
	return (true);
}

static t_int_pts	get_min_vect(t_int_pts cur, t_vec_pos *new, \
						t_geom *geom, t_vec_pos vps)
{
	t_int_pts	out;
	double		long_cur;
	int			i;

	out = cur;
	if (!new)
		return (cur);
	long_cur = modulo_vector(cur.pt.pt);
	i = -1;
	while(++i < 2)
	{
		if (!is_behind_cam(new[i], vps))
		{
			if(modulo_vector(new[i].pt) < long_cur)
			{
				out.pt = new[i];
				out.pt.c = geom->color;
				out.geom = geom;
			}
		}
		if(geom->type == PLANE)
			i++;
	}
	return (out);
}

t_vec_pos	*get_int_pt(t_vec_pos *vps, t_geom *geo)
{
	t_vec_pos	*out;

	if (geo->type == SPHERE)
		out = int_vect_esfera(*vps, geo->vp.pt, geo->r);
//	else if (geo->type == CYLINDER)
//		out = int_vect_cilind(*vps, geo->vp, geo->r, geo->height);
	else if (geo->type == PLANE)
		out = int_vect_plano(*vps, geo->vp);
	else if (geo->type == CYLINDER)
		out = int_vect_cono(*vps, geo->vp, geo->r, geo->height);
	else
		out = NULL;
	return (out);
}

/// @brief Gives the color of the closest surface to the pixel.
/// @param pixel
/// @param field
void	get_colored_int_pt(int pixel, t_field *field)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_int_pts	*vp_int;
	t_vec_pos	*vps;

	ptr = field->geom;
	vps = &field->camera.field_vp[pixel];
	vp_int = &field->camera.int_vp[pixel];
	vp_int->pt = init_vp(vps->c);
	vp_int->geom = NULL;
	while (ptr)
	{
		out = get_int_pt(vps, ptr);
		if (out != NULL)
		{
			*vp_int = get_min_vect(*vp_int, out, ptr, *vps);
			vps->c = vp_int->pt.c;
			free(out);
		}
		ptr = ptr->next;
	}
	vp_int->pt.c = set_pixel_color(*vp_int, field, *vps);
}
