/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:39:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 10:33:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

bool	ambient_light_data_check(char **content)
{
	if (ft_array_size(content) != 3)
		return (false);
	if (!ft_isdouble(content[1]) || \
		ratio_double_error(0.0, 1.0, ft_atof(content[1])))
		return (false);
	if (ft_is_rgb(content[2]))
	{
		if (!ft_check_rgb_ratio(content[2]))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	camera_data_check(char **content)
{
	if (ft_array_size(content) != 4)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (ft_is_vec3(content[2]))
	{
		if (!ft_check_vect3_ratio(content[2], -1, 1))
			return (false);
	}
	else
		return (false);
	if (!ft_isnumeric(content[3]) || \
		ratio_int_error(0, 180, ft_atoi(content[3])))
		return (false);
	return (true);
}

bool	light_data_check(char **content)
{
	if (ft_array_size(content) != 4)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (ft_isdouble(content[2]))
	{
		if (ratio_double_error(0, 1, ft_atof(content[2])))
			return (false);
	}
	else
		return (false);
	return (true);
}
