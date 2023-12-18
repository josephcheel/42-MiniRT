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

static t_vec_pos	get_min_vect(t_vec_pos cur, t_vec_pos *new, t_geom *geom)
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
		out = new[0];
		out.c = geom->color;
	}
	if (geom->type != PLANE)
	{
		long_cur = modulo_vector(out.pt);
		long_new = modulo_vector(new[1].pt);
		if (long_cur > long_new)
		{
			out = new[1];
			out.c = geom->color;
		}
	}
	return (out);
}

t_vec_pos	get_int_pt(t_vec_pos vps, t_geom *geom)
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
			vp_int = get_min_vect(vp_int, out, ptr);
		free(out);
		ptr = ptr->next;
	}
	return (vp_int);
}
