/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ref_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:53:12 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/30 11:53:18 by eavedill         ###   ########.fr       */
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

static void create_ref(t_vec_pos *vps, t_int_pts *vp_int, t_vec_pos *out,
					   t_geom *ptr)
{
	double ax;

	vp_int = get_min_vect(vp_int, out, ptr, vps);
	vp_int->ref.vz = vp_int->pt.v;
	ax = round(prod_escalar(vp_int->pt.v, create_vect(0, 0, 1)) * 1E5) / 1E5;
	if (ax == 1 || ax == -1)
	{
		if (vp_int->ref.vz.z == 0)
		{
			vp_int->ref.vz = create_vect(0, 0, 1);
			vp_int->ref.vy = create_vect(0, 1, 0);
		}
		if (vp_int->ref.vz.z > 0)
			vp_int->ref.vy = create_vect(0, 1, 0);
		else
			vp_int->ref.vy = create_vect(0, -1, 0);
		vp_int->ref.vx = create_vect(1, 0, 0);
	}
	else
	{
		vp_int->ref.vx = conv_v_unit(prod_vectorial(
			create_vect(0, 0, 1), vp_int->ref.vz));
		vp_int->ref.vy = conv_v_unit(
			prod_vectorial(vp_int->ref.vz, vp_int->ref.vx));
	}
}
/*
to print in case of error.
//	vp_int->pt.v = prod_cte_vector(ptr->sense, vp_int->pt.v);
//	ft_print_vec3("Valor de vp.pt", vp_int->pt.pt);
//	ft_print_vec3("Valor de vp.v", vp_int->pt.v);
//	printf("valores de aux %f -- %f\n", ax[1], ax[0]);ax[0] == 0 ||
//		ft_print_vec3("Valor de vp.vz ", vp_int->ref.vz);
//		ft_print_vec3("Valor de vp.vx ", vp_int->ref.vx);
//		ft_print_vec3("Valor de vp.vy ", vp_int->ref.vy);
*/
