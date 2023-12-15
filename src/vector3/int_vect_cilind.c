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

static t_vec_pos	*get_point_result(double *lambda, t_vec_pos vpi, \
							t_vec_pos vpc)
{
	t_vec_pos	*out;
	double		lambda_c;
	t_vec3		aux;

	out = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
	out[0].pt = prod_cte_vector(lambda[0], vpi.v);
	out[0].pt = suma_vector(out[0].pt, vpi.pt);
	out[1].pt = prod_cte_vector(lambda[1], vpi.v);
	out[1].pt = suma_vector(out[1].pt, vpi.pt);
	aux = resta_vector(vpi.pt, vpc.pt);
	lambda_c = prod_escalar(vpc.v, aux) + \
				lambda[0] * prod_escalar(vpi.v, vpc.v);
	lambda_c = lambda_c / prod_escalar(vpc.v, vpc.v);
	aux = suma_vector(vpc.pt, prod_cte_vector(lambda_c, vpc.v));
	out[0].v = conv_vect_unit(resta_vector(out[0].pt, aux));
	out[1].v = conv_vect_unit(resta_vector(out[1].pt, aux));
	return (out);
}

t_vec_pos	*int_vect_cilind(t_vec_pos vpi, t_vec_pos vpc, double r)
{
	t_vec3		vaux[2];
	t_vec3		pci;
	t_vec_pos	*out;
	double		*lambda;

	pci = resta_vector(vpi.pt, vpc.pt);
	vaux[0] = prod_cte_vector(prod_escalar(vpc.v, pci), vpc.v);
	vaux[0] = div_cte_vector(prod_escalar(vpc.v, vpc.v), vaux[0]);
	vaux[0] = resta_vector(pci, vaux[0]);
	vaux[1] = prod_cte_vector(prod_escalar(vpi.v, vpc.v), vpc.v);
	vaux[1] = div_cte_vector(prod_escalar(vpc.v, vpc.v), vaux[1]);
	vaux[1] = resta_vector(vpi.v, vaux[1]);
	lambda = calc_lambda(vaux, r);
	if (!lambda)
		return (NULL);
	out = get_point_result(lambda, vpi, vpc);
	free(lambda);
	return (out);
}
