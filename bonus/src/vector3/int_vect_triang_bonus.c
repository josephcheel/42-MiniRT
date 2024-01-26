/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_plano.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 18:37:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

bool	is_out_triang(t_vec_pos *vp, t_geom *tr)
{
	t_vec3	aux[3];
	double	ang;

	aux[0] = conv_v_unit(resta_vector(tr->vp.pt, vp->pt));
	aux[1] = conv_v_unit(resta_vector(tr->vp1.pt, vp->pt));
	aux[2] = conv_v_unit(resta_vector(tr->vp2.pt, vp->pt));
	ang = acos(prod_escalar(aux[0], aux[1]));
	ang += acos(prod_escalar(aux[0], aux[2]));
	ang += acos(prod_escalar(aux[1], aux[2]));
	if (ang < 2 * M_PI - 0.000000001)
		return (true);
	return (false);
}

t_vec_pos	*int_vect_triang(t_vec_pos pi, t_geom *tr)
{
	double		lambda;
	t_vec_pos	*out;

	out = int_vect_plano(pi, tr->vp);
	if (is_out_triang(out, tr))
	{
		free(out);
		return (NULL);
	}
	return (out);
}
