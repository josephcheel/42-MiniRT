/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_pto_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/05 13:01:06 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	dist_pto_vector(t_vec3 p1, t_vec3 p2, t_vec3 v)
{
	double	out;
	double	prod;
	t_vec3	v2;

	v2 = resta_vector(p2, p1);
	prod = prod_escalar(v, v2) / modulo_vector(v);
	out = sqrt(prod_escalar(v2, v2) - prod * prod);
	return (out);
}
