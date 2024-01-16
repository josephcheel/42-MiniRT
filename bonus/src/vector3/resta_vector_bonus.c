/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resta_vector_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	resta_vector(t_vec3 a, t_vec3 b)
{
	t_vec3	out;

	out.x = a.x - b.x;
	out.y = a.y - b.y;
	out.z = a.z - b.z;
	return (out);
}
