/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_cono.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/14 14:46:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static double	*calc_lambda_c(t_vec3 *v, double r, double h)
{
	double	p[3];
	double	*lambda_c;
	int		i;

	p[0] = prod_escalar(v[1], v[1]) * h * h - r * r;
	p[1] = 2 * (prod_escalar(v[0], v[1]) * h * h + r * r * h);
	p[2] = (prod_escalar(v[0], v[0]) - r * r) * h * h;
	lambda_c = solv_eq_ord_2(p);
	if (lambda_c == NULL)
		return (NULL);
	i = -1;
	while (++i < 2)
	{
		if (lambda_c[i] < 0)
			lambda_c[i] = 0;
		else if (lambda_c[i] > h)
			lambda_c[i] = h;
	}
	return (lambda_c);
}

static double	*calc_lambda(double *lambda_c, t_vec_pos vpi, t_vec_pos vpc)
{
	double	*lambda;
	t_vec3	pci;
	int		i;

	pci = resta_vector(vpi.pt, vpc.pt);
	i = -1;
	lambda = (double *)malloc(2 * sizeof(double));
	while (++i < 2)
	{
		lambda[i] = lambda_c[i] * prod_escalar(vpc.v, vpc.v);
		lambda[i] = lambda[i] - prod_escalar(vpc.v, pci);
		lambda[i] = lambda[i] / prod_escalar(vpc.v, vpi.v);
	}
	return (lambda);
}

static t_vec_pos	*calculate_point(double *lambda, double \
				*lambda_c, t_vec_pos vpi, t_vec_pos vpc)
{
	t_vec_pos	*out;
	t_vec_pos	aux;
	t_vec_pos	*out_aux;
	int			i;

	out = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
	i = -1;
	while (++i < 2)
	{
		if (lambda_c[i] == 0)
		{
			aux = vpc;
			aux.v = prod_cte_vector(-1, aux.v);
			out_aux = int_vect_plano(vpi, aux);
			out[i] = out_aux[0];
			free(out_aux);
		}
		else
		{
			out[i].pt = prod_cte_vector(lambda[i], vpi.v);
			out[i].pt = suma_vector(out[i].pt, vpi.pt);
			aux.pt = suma_vector(vpc.pt, prod_cte_vector(lambda_c[i], vpc.v));
			out[i].v = conv_v_unit(resta_vector(out[i].pt, aux.pt));
		}
	}
	return (out);
}

static t_vec_pos	*get_point_result(double *lambda_c, t_vec_pos vpi, \
							t_vec_pos vpc, double h)
{
	t_vec_pos	*out;
	double		*lambda;

	if ((lambda_c[0] == 0 && lambda_c[1] == 0) || \
		(lambda_c[0] == h && lambda_c[1] == h))
		return (NULL);
	lambda = calc_lambda(lambda_c, vpi, vpc);
	out = calculate_point(lambda, lambda_c, vpi, vpc);
	free(lambda);
	return (out);
}

t_vec_pos	*int_vect_cono(t_vec_pos vpi, t_vec_pos vpc, double r, double h)
{
	t_vec3		vaux[2];
	t_vec3		pci;
	t_vec_pos	*out;
	double		*lambda_c;

	pci = resta_vector(vpi.pt, vpc.pt);
	vaux[0] = prod_cte_vector(prod_escalar(vpc.v, pci), vpi.v);
	vaux[0] = div_cte_vector(prod_escalar(vpc.v, vpi.v), vaux[0]);
	vaux[0] = resta_vector(pci, vaux[0]);
	vaux[1] = prod_cte_vector(prod_escalar(vpc.v, vpc.v), vpi.v);
	vaux[1] = div_cte_vector(prod_escalar(vpc.v, vpi.v), vaux[1]);
	vaux[1] = resta_vector(vaux[1], vpc.v);
	lambda_c = calc_lambda_c(vaux, r, h);
	if (!lambda_c)
		return (NULL);
	out = get_point_result(lambda_c, vpi, vpc, h);
	free(lambda_c);
	return (out);
}
