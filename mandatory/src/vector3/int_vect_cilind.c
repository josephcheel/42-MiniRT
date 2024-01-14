/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_cilind.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/13 12:36:44 by jcheel-n         ###   ########.fr       */
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
		lambda_c[i] = prod_escalar(vpc.v, pci) + lambda[i] \
						* prod_escalar(vpi.v, vpc.v);
		lambda_c[i] = lambda_c[i];
		if (lambda_c[i] > h)
			lambda_c[i] = h;
		else if (lambda_c[i] < 0)
			lambda_c[i] = 0;
	}
	return (lambda_c);
}

static t_vec_pos	get_dir_pos_plane(double lambda, t_vec_pos vpc, double h)
{
	t_vec_pos	aux;

	aux = vpc;
	if (lambda == 0)
		aux.v = prod_cte_vector(-1, aux.v);
	else
		aux.pt = suma_vector(vpc.pt, prod_cte_vector(h, vpc.v));
	return (aux);
}

static t_vec_pos	*get_point_result(double **lambda, t_vec_pos vpi, \
							t_vec_pos vpc, double h)
{
	t_vec_pos	*out[2];
	t_vec_pos	aux;
	int			i;

	out[0] = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
	i = -1;
	while (++i < 2)
	{
		if (lambda[1][i] == 0 || lambda[1][i] == h)
		{
			aux = get_dir_pos_plane(lambda[1][i], vpc, h);
			out[1] = int_vect_plano(vpi, aux);
			out[0][i] = out[1][0];
			free(out[1]);
		}
		else
		{
			out[0][i].pt = prod_cte_vector(lambda[0][i], vpi.v);
			out[0][i].pt = suma_vector(out[0][i].pt, vpi.pt);
			aux.pt = suma_vector(vpc.pt, prod_cte_vector(lambda[1][i], vpc.v));
			out[0][i].v = conv_v_unit(resta_vector(out[0][i].pt, aux.pt));
		}
	}
	return (out[0]);
}

/// @brief Detect intersecion point between line and cylinder.
/// @param vpi line that intersects
/// @param vpc Vector direction of cylinder
/// @param r Cuyinder radius
/// @param h Cylinder high
/// @return 2 t_vec_pos as points of intersection
//	Note:
// lambda[0] = lambda_i
// lambda[1] = lambda_c
t_vec_pos	*int_vect_cilind(t_vec_pos vpi, t_vec_pos vpc, double r, double h)
{
	t_vec3		vaux[2];
	t_vec3		pci;
	t_vec_pos	*out;
	double		*lambda[2];

	pci = resta_vector(vpi.pt, vpc.pt);
	vaux[0] = prod_cte_vector(prod_escalar(vpc.v, pci), vpc.v);
	vaux[0] = resta_vector(pci, vaux[0]);
	vaux[1] = prod_cte_vector(prod_escalar(vpi.v, vpc.v), vpc.v);
	vaux[1] = resta_vector(vpi.v, vaux[1]);
	lambda[0] = calc_lambda(vaux, r);
	if (!lambda[0])
		return (NULL);
	lambda[1] = limit_lambda(lambda[0], vpi, vpc, h);
	if ((lambda[1][0] == 0 && lambda[1][1] == 0) \
				|| (lambda[1][0] == h && lambda[1][1] == h))
	{
		free(lambda[0]);
		free(lambda[1]);
		return (NULL);
	}
	out = get_point_result(lambda, vpi, vpc, h);
	free(lambda[0]);
	free(lambda[1]);
	return (out);
}
