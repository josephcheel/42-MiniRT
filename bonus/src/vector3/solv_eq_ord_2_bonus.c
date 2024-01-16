/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_eq_ord_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_bonus.h"

double	*solv_eq_ord_2(double *p)
{
	double	*out;
	double	aux;

	if (p[1] * p[1] < 4 * p[0] * p[2])
		return (NULL);
	out = (double *)malloc(2 * sizeof(double));
	if (out == NULL)
		return (out);
	if (p[0] == 0)
	{
		out[0] = -p[2] / p[1];
		out[1] = -p[2] / p[1];
		return (out);
	}
	aux = sqrt(p[1] * p[1] - 4 * p[0] * p[2]);
	out[0] = (-p[1] + aux) / (2 * p[0]);
	out[1] = (-p[1] - aux) / (2 * p[0]);
	return (out);
}
