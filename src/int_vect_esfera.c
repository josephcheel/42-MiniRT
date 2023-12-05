/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_esfera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 18:37:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vector	*int_vect_esfera(t_vector p1, t_vector v1, t_vector pr, double r)
{
	t_vector	*pt;
	double		param[2];
	t_vector	v2;
	double		out;

	if (dist_pto_vector(p1, v1, pr) > r)
		return (NULL);
	pt = (t_vector *)malloc(2 * sizeof(t_vector));
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
