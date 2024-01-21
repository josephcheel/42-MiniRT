/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:39:52 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 15:50:53 by jcheel-n         ###   ########.fr       */
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

static bool	checkboard_color_check(char *content)
{
	const char	*colors[8] = {"BLACK", "RED", "GREEN", \
	"YELLOW", "BLUE", "MAGENTA", "CYAN", "WHITE"};

	if (ft_isallalpha(content))
	{
		if (!ft_isstrarray(content, (char **)colors))
			return (false);
	}
	else if (!ft_is_rgb(content) || !ft_check_rgb_ratio(content))
		return (false);
	return (true);
}

bool	checkboard_data_check(char **content)
{
	if (ft_array_size(content) != 4 && ft_array_size(content) != 5)
		return (false);
	if (!checkboard_color_check(content[1]))
		return (false);
	if (!checkboard_color_check(content[2]))
		return (false);
	if (!ft_isdouble(content[3]))
		return (false);
	if (ft_array_size(content) == 5)
	{
		if (!ft_isnumeric(content[4]))
			return (false);
	}
	return (true);
}
