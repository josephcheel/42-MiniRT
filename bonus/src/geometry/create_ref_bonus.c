/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ref_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:53:12 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/29 19:53:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static t_int_pts	*get_min_vect(t_int_pts *cur, t_vec_pos *new,
						t_geom *geom, t_vec_pos *pixl)
{
	t_int_pts	*out;
	double		long_cur;
	int			i;

	out = cur;
	if (!new)
		return (out);
	long_cur = modulo_vector(resta_vector(cur->pt.pt, pixl->pt));
	i = -1;
	while (++i < 2)
	{
		if (modulo_vector(resta_vector(new[i].pt, pixl->pt)) < long_cur)
		{
			out->pt = new[i];
			out->pt.c = geom->color;
			out->geom = geom;
		}
	}
	return (out);
}

void	create_ref(t_vec_pos *vps, t_int_pts *vp_int, t_vec_pos *out, \
			t_geom *ptr)
{
	vp_int = get_min_vect(vp_int, out, ptr, vps);
	vp_int->pt.v = prod_cte_vector(ptr->sense, vp_int->pt.v);
	vp_int->ref.vz = vp_int->pt.v;
	if (vp_int->ref.vz.x == 0 && vp_int->ref.vz.y == 0)
	{
		if (vp_int->ref.vz.z > 0)
			vp_int->ref.vy = create_vect(0, 1, 0);
		else
			vp_int->ref.vy = create_vect(0, -1, 0);
		vp_int->ref.vx = create_vect(1, 0, 0);
	}
	else
	{
		vp_int->ref.vx = conv_v_unit(prod_vectorial(\
							create_vect(0, 0, 1), vp_int->ref.vz));
		vp_int->ref.vy = conv_v_unit(prod_vectorial(vp_int->ref.vz, \
							vp_int->ref.vx));
	}
}
