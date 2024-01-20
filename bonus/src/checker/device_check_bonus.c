/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:39:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/20 22:38:31 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

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

bool	checkboard_data_check(char **content)
{
	const char	*colors[] = {"BLACK", "RED", "GREEN", \
	"YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE"};

	if (ft_array_size(content) != 3)
		return (false);
	if (ft_isallalpha(content[1]))
	{
		if (!ft_isstrarray(content[1], (char **)colors))
			return (false);
	}
	if (!ft_is_rgb(content[1]) || !ft_check_rgb_ratio(content[1]))
		return (false);
	if (ft_isallalpha(content[1]))
	{
		if (!ft_isstrarray(content[2], (char **)colors))
			return (false);
	}
	if (!ft_is_rgb(content[2]) || !ft_check_rgb_ratio(content[2]))
		return (false);
	return (true);
}

// bool	bumpmap_data_check(char **content)
// {
// 	if (ft_array_size(content) != 2)
// 		return (false);
// 	if (ft_check_extension(content[1], ".xpm"))
// 		return (false);
// 	if (!ft_strchr(content[1], '/'))
// 	{
// 		write(2, "Path must be absolute", 39);
// 		return (false);
// 	}
// 	return (true);
// }
