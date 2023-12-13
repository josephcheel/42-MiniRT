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

t_vec3	*int_vect_esfera(t_vec3 p1, t_vec3 v1, t_vec3 pr, double r)
{
	t_vec3	*pt;
	double	param[3];
	t_vec3	v2;
	double	*lambda;

	if (dist_pto_vector(p1, v1, pr) > r)
		return (NULL);
	v2 = resta_vector(p1, pr);
	param[0] = prod_escalar(v1, v1);
	param[1] = 2 * prod_escalar(v1, v2);
	param[2] = prod_escalar(v2, v2) - r * r;
	lambda = solv_eq_ord_2(param);
	if (lambda != NULL)
	{
		pt = (t_vec3 *)malloc(2 * sizeof(t_vec3));
		if (pt == NULL)
			return (NULL);
		pt[0] = suma_vector(p1, prod_cte_vector(lambda[0], v1));
		pt[1] = suma_vector(p1, prod_cte_vector(lambda[1], v1));
	}
	else
	{
		return (NULL);
	}
	return (pt);
}
