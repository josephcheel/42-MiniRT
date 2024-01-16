/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:37:41 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

bool	plane_data_check(char **content)
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
	if (ft_is_rgb(content[3]))
	{
		if (!ft_check_rgb_ratio(content[3]))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	sphere_data_check(char **content)
{
	if (ft_array_size(content) != 4)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (!ft_isdouble(content[2]))
		return (false);
	if (ft_is_rgb(content[3]))
	{
		if (!ft_check_rgb_ratio(content[3]))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	cylinder_data_check(char **content)
{
	if (ft_array_size(content) != 6)
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
	if (!ft_isdouble(content[3]))
		return (false);
	if (!ft_isdouble(content[4]))
		return (false);
	if (ft_is_rgb(content[5]))
	{
		if (!ft_check_rgb_ratio(content[5]))
			return (false);
	}
	else
		return (false);
	return (true);
}
