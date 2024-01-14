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

#include "../../inc/minirt_bonus.h"

t_vec_pos	*int_vect_plano(t_vec_pos pi, t_vec_pos pl)
{
	double		lambda;
	t_vec_pos	*out;

	out = (t_vec_pos *)malloc(2 * sizeof(t_vec_pos));
	if (!out)
		return (NULL);
	out[0].pt = resta_vector(pl.pt, pi.pt);
	lambda = prod_escalar(pl.v, out[0].pt) / prod_escalar(pl.v, pi.v);
	out[0].pt = prod_cte_vector(lambda, pi.v);
	out[0].pt = suma_vector(pi.pt, out[0].pt);
	out[0].v = pl.v;
	out[1] = init_vp(pi.c);
	return (out);
}
