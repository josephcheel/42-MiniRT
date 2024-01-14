/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_cte_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 18:38:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	div_cte_vector(double a, t_vec3 b)
{
	t_vec3	out;

	out.x = b.x / a;
	out.y = b.y / a;
	out.z = b.z / a;
	return (out);
}
