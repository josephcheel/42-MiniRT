/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_dot_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:51:29 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/27 17:53:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	vect_dot_matrix(t_vec3 v, t_matrix m)
{
	t_vec3	out;

	out.x = v.x * m.vx.x + v.y * m.vy.x + v.z * m.vz.x;
	out.y = v.x * m.vx.y + v.y * m.vy.y + v.z * m.vz.y;
	out.z = v.x * m.vx.z + v.y * m.vy.z + v.z * m.vz.z;
	return (out);
}
