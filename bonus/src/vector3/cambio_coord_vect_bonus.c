/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cambio_coord_vect_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:38:56 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/27 17:54:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	cambio_coord_vect(t_vec3 v, t_matrix m)
{
	t_vec3	out;

	out.x = prod_escalar(v, m.vx);
	out.y = prod_escalar(v, m.vy);
	out.z = prod_escalar(v, m.vz);
	return (out);
}