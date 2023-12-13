/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vect_plano.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 18:37:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec3	int_vect_plano(t_vec3 pt, t_vec3 v, t_vec3 pt_pl, t_vec3 v_pl)
{
	double	lambda;
	t_vec3	out;

	out = resta_vector(pt_pl, pt);
	lambda = prod_escalar(v_pl, out) / prod_escalar(v_pl, v);
	out = prod_cte_vector(lambda, v);
	out = suma_vector(pt, out);
	return (out);
}
