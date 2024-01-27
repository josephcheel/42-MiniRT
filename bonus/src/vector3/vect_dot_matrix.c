/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_dot_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:51:29 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/27 10:59:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	vect_dot_matrix(t_vec3 v, t_matrix m)
{
	t_vec3	out;

	out.x = v.x * m.x.x + v.y * m.y.x + v.z * m.z.x;
	out.y = v.x * m.x.y + v.y * m.y.y + v.z * m.z.y;
	out.z = v.x * m.x.z + v.y * m.y.z + v.z * m.z.z;
	return (out);
}