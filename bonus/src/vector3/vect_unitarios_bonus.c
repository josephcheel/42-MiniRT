/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_unitarios_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:47:26 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/27 17:55:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	vect_unit_x(void)
{
	return (create_vect(1, 0, 0));
}

t_vec3	vect_unit_y(void)
{
	return (create_vect(0, 1, 0));
}

t_vec3	vect_unit_z(void)
{
	return (create_vect(0, 0, 1));
}
