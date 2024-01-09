/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_cilind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/09 23:14:23 by jcheel-n         ###   ########.fr       */
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

static double	*limit_lambda(double *lambda, t_vec_pos vpi, \
					t_vec_pos vpc, double h)
{
	double	*lambda_c;
	t_vec3	pci;
	int		i;

	pci = resta_vector(vpi.pt, vpc.pt);
	i = -1;
	lambda_c = (double *) malloc(2 * sizeof(double));
	while (++i < 2)
	{
		lambda_c[i] = prod_escalar(vpc.v, pci) + lambda[i] * \
				prod_escalar(vpi.v, vpc.v);
		lambda_c[i] = lambda_c[i] / prod_escalar(vpc.v, vpc.v);
		if (lambda_c[i] > h)
			lambda_c[i] = h;
		else if (lambda_c[i] < 0)
			lambda_c[i] = 0;
	}
	return (lambda_c);
}

static t_vec_pos	*get_point_result(double *lambda, t_vec_pos vpi, \
							t_vec_pos vpc, double h)
{
	t_vec_pos	*out;
	double		*lambda_c;
	t_vec_pos	aux;
	int			i;

	lambda_c = limit_lambda(lambda, vpi, vpc, h);
	if (lambda_c[0] == 0 && lambda_c[1] == 0)
		return (NULL);
	if (lambda_c[0] == h && lambda_c[1] == h)
		return (NULL);
	out = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
	i = -1;
	while (++i < 2)
	{
		if (lambda_c[i] == 0)
		{
			aux = vpc;
			aux.v = prod_cte_vector(-1, aux.v);
			out[i] = int_vect_plano(vpi, aux)[0];
		}
		else if (lambda_c[i] == h)
		{
			aux = vpc;
			aux.pt = suma_vector(vpc.pt, prod_cte_vector(h, vpc.v));
			out[i] = int_vect_plano(vpi, aux)[0];
		}
		else
		{
			out[i].pt = prod_cte_vector(lambda[i], vpi.v);
			out[i].pt = suma_vector(out[i].pt, vpi.pt);
			aux.pt = suma_vector(vpc.pt, prod_cte_vector(lambda_c[i], vpc.v));
			out[i].v = conv_v_unit(resta_vector(out[i].pt, aux.pt));
		}
	}
	free(lambda_c);
	return (out);
}

t_vec_pos	*int_vect_cilind(t_vec_pos vpi, t_vec_pos vpc, double r, double h)
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
	out = get_point_result(lambda, vpi, vpc, h);
	free(lambda);
	return (out);
}
