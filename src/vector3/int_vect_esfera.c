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
	double	param[2];
	t_vec3	v2;
	double	out;

	if (dist_pto_vector(p1, v1, pr) > r)
		return (NULL);
	pt = (t_vec3 *)malloc(2 * sizeof(t_vec3));
	if (pt == NULL)
		return (NULL);
	v2 = resta_vector(pr, p1);
	param[0] = 2 * prod_escalar(v1, v2);
	param[1] = prod_escalar(pr, pr) - r * r;
	out = param[0] + sqrt(param[0] * param[0] - param[1]);
	pt[0] = suma_vector(p1, prod_cte_vector(out, v1));
	out = param[0] + sqrt(param[0] * param[0] - param[1]);
	pt[1] = suma_vector(p1, prod_cte_vector(out, v1));
	return (pt);
}
