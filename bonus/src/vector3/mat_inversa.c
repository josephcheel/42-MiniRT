/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_inversa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:25:42 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/27 17:55:37 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_matrix	mat_inversa(t_matrix m)
{
	t_matrix	out;

	out = m;
	out.vx.y = m.vy.x;
	out.vy.x = m.vx.y;
	out.vx.z = m.vz.x;
	out.vz.x = m.vx.z;
	out.vy.z = m.vz.y;
	out.vz.y = m.vy.z;
	return (out);
}