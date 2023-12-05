/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resta_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 18:38:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vector	resta_vector(t_vector a, t_vector b)
{
	t_vector	out;

	out.x = a.x - b.x;
	out.y = a.y - b.y;
	out.z = a.z - b.z;
	return (out);
}