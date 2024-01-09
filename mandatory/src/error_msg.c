/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:12:21 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/09 13:15:17 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_geom *geom_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (NULL);
}

int ratio_vec3_error(int min, int max, t_vec3 vector)
{
	if (ratio_double_error(min, max, vector.x) ||
	ratio_double_error(min, max, vector.y) ||
	ratio_double_error(min, max, vector.z))
		return (1);
	return (0);
}

int	ratio_int_error(int min, int max, int nbr)
{
	if (nbr < min || nbr > max)
		return (1);
	return (0);
}

int	ratio_double_error(double min, double max, double nbr)
{
	if (nbr < min || nbr > max)
		return (1);
	return (0);
}

/*
Returns 1 if color is out of range returns 0 if color is OK
*/
int rgb_error(t_color color)
{
	if (!((color.r >= 0 && color.r <= 255) &&
		(color.g >= 0 && color.g <= 255) &&
		(color.b >= 0 && color.b <= 255)
		))
		return (1);
	return (0);
}
