/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_esfera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/05 13:01:05 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec_pos	*int_vect_esfera(t_vec_pos vpi, t_vec3 pr, double r)
{
	t_vec_pos	*pt;
	double		param[3];
	t_vec3		v2;
	double		*lambda;

	if (dist_pto_vector(vpi.pt, pr, vpi.v) > r)
		return (NULL);
	v2 = resta_vector(vpi.pt, pr);
	param[0] = prod_escalar(vpi.v, vpi.v);
	param[1] = 2 * prod_escalar(vpi.v, v2);
	param[2] = prod_escalar(v2, v2) - r * r;
	lambda = solv_eq_ord_2(param);
	if (lambda != NULL)
	{
		pt = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
		if (pt == NULL)
			return (NULL);
		pt[0].pt = suma_vector(vpi.pt, prod_cte_vector(lambda[0], vpi.v));
		pt[1].pt = suma_vector(vpi.pt, prod_cte_vector(lambda[1], vpi.v));
		pt[0].v = conv_v_unit(resta_vector(pt[0].pt, pr));
		pt[1].v = conv_v_unit(resta_vector(pt[1].pt, pr));
	}
	else
		return (NULL);
	return (pt);
}
