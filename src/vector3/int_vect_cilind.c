/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_cilind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 18:37:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static double	*calc_lambda(t_vec3 *v, double r)
{
	double	*p;
	double	*out;

	p = (double *)malloc(3 * sizeof(double));
	if (p == NULL)
		return (NULL);
	p[0] = prod_escalar(v[1], v[1]);
	p[1] = 2 * prod_escalar(v[0], v[1]);
	p[2] = prod_escalar(v[0], v[0]) - r * r;
	out = solv_eq_ord_2(p);
	free(p);
	return (out);
}

static t_vec3	*get_vect_result(double *lambda, t_vec3 p1, t_vec3 v1)
{
	t_vec3	*out;

	out = (t_vec3 *)malloc(2 * sizeof(t_vec3));
	out[0] = prod_cte_vector(lambda[0], v1);
	out[0] = suma_vector(out[0], p1);
	out[1] = prod_cte_vector(lambda[1], v1);
	out[1] = suma_vector(out[1], p1);
	return (out);
}

t_vec3	*int_vect_cilind(t_vec3 p1, t_vec3 v1, t_vec3 pc, t_vec3 vc, double r)
{
	t_vec3	vaux[2];
	t_vec3	pci;
	t_vec3	*out;
	double	*lambda;

	pci = resta_vector(p1, pc);
	vaux[0] = prod_cte_vector(prod_escalar(vc, pci), vc);
	vaux[0] = div_cte_vector(prod_escalar(vc, vc), vaux[0]);
	vaux[0] = resta_vector(pci, vaux[0]);
	vaux[1] = prod_cte_vector(prod_escalar(v1, vc), vc);
	vaux[1] = div_cte_vector(prod_escalar(vc, vc), vaux[1]);
	vaux[1] = resta_vector(v1, vaux[1]);
	lambda = calc_lambda(vaux, r);
	if (!lambda)
		return (NULL);
	out = get_vect_result(lambda, p1, v1);
	free(lambda);
	return (out);
}
