/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/27 17:53:18 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

/// @brief This function applies a rotation matrix from orthonogal reference.
/// @brief Order of rotations are: rot with respectx rot with respect y and
/// @brief rot with respect z.
/// @param v Vector to be rotated
/// @param ang Vector representing the 3 angles of rotation respect x,y,z.
/// @return returns a t_vec3 which represents the new direction of the vector.
t_vec3	martix_rot(t_vec3 v, t_vec3 ang)
{
	t_matrix	m;
	t_vec3		out;

	m.vx.x = cos(ang.y) * cos(ang.z);
	m.vx.y = -cos(ang.y) * sin(ang.z);
	m.vx.z = -sin(ang.y);
	m.vy.x = -sin(ang.x) * sin(ang.y) * cos(ang.z) + cos(ang.x) * sin(ang.z);
	m.vy.y = sin(ang.x) * sin(ang.y) * sin(ang.z) + cos(ang.x) * cos(ang.z);
	m.vy.z = -sin(ang.x) * cos(ang.y);
	m.vz.x = cos(ang.x) * sin(ang.y) * cos(ang.z) + sin(ang.x) * sin(ang.z);
	m.vz.y = -cos(ang.x) * sin(ang.y) * sin(ang.z) + sin(ang.x) * cos(ang.z);
	m.vz.z = cos(ang.x) * cos(ang.y);
	out = vect_dot_matrix(v, m);
	return (out);
}
