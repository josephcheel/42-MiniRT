/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

/// @brief This function rotates a n angle a vector v using the direction of 
/// @brief the vector k. The sense of rotation uses the standard rule of 
/// @brief vectorial product
/// @param v Vector to be rotated 
/// @param k Vector representing the axis of rotation 
/// @param ang_rot Angle to rotate vector v
/// @return returns a t_vec3 which represents the new position of the vector.
t_vec3	rotate_vector(t_vec3 v, t_vec3 k, double ang_rot)
{
	t_vec3	aux[4];

	aux[0] = prod_cte_vector(cos(ang_rot), v);
	aux[1] = prod_cte_vector(sin(ang_rot), prod_vectorial(k, v));
	aux[2] = prod_cte_vector((1 - cos(ang_rot)) * prod_escalar(k, v), k);
	aux[3] = suma_vector(aux[0], aux[1]);
	return (suma_vector(aux[2], aux[3]));
}
