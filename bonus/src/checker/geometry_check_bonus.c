/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:37:41 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/30 14:21:59 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

bool	plane_data_check(char **content)
{
	int	size;

	size = ft_array_size(content);
	if (size != 4 && size != 5 && size != 6)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (!ft_is_vec3(content[2]) || !ft_check_vect3_ratio(content[2], -1, 1))
		return (false);
	if (!ft_is_rgb(content[3]) || !ft_check_rgb_ratio(content[3]))
		return (false);
	if (size == 5 && (!bumpmap_data_check(content[4]) && \
		ft_strcmp(content[4], "NO_CHECKBOARD") != 0))
		return (false);
	if (size == 6 && (!bumpmap_data_check(content[5]) && \
		ft_strcmp(content[5], "NO_CHECKBOARD") != 0))
		return (false);
	return (true);
}

bool	sphere_data_check(char **content)
{
	int	size;

	size = ft_array_size(content);
	if (size != 4 && size != 5 && size != 6)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (!ft_isdouble(content[2]))
		return (false);
	if (!ft_is_rgb(content[3]) || !ft_check_rgb_ratio(content[3]))
		return (false);
	if (size == 5 && (!bumpmap_data_check(content[4]) && \
		ft_strcmp(content[4], "NO_CHECKBOARD") != 0))
		return (false);
	if (size == 6 && (!bumpmap_data_check(content[5]) && \
		ft_strcmp(content[5], "NO_CHECKBOARD") != 0))
		return (false);
	return (true);
}

bool	cylinder_data_check(char **content)
{
	int	size;

	size = ft_array_size(content);
	if (size != 6 && size != 7 && size != 8)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (!ft_is_vec3(content[2]) || !ft_check_vect3_ratio(content[2], -1, 1))
		return (false);
	if (!ft_isdouble(content[3]))
		return (false);
	if (!ft_isdouble(content[4]))
		return (false);
	if (!ft_is_rgb(content[5]) || !ft_check_rgb_ratio(content[5]))
		return (false);
	if (size == 7 && (!bumpmap_data_check(content[6]) && \
		ft_strcmp(content[6], "NO_CHECKBOARD") != 0))
		return (false);
	if (size == 8 && (!bumpmap_data_check(content[7]) && \
		ft_strcmp(content[7], "NO_CHECKBOARD") != 0))
		return (false);
	return (true);
}

bool	triangle_data_check(char **content)
{
	int	size;

	size = ft_array_size(content);
	if (size != 5 && size != 6 && size != 7)
		return (false);
	if (!ft_is_vec3(content[1]))
		return (false);
	if (!ft_is_vec3(content[2]))
		return (false);
	if (!ft_is_vec3(content[3]))
		return (false);
	if (!ft_is_rgb(content[4]) || !ft_check_rgb_ratio(content[4]))
		return (false);
	if (size == 6 && (!bumpmap_data_check(content[5]) && \
		ft_strcmp(content[5], "NO_CHECKBOARD") != 0))
		return (false);
	if (size == 7 && (!bumpmap_data_check(content[6]) && \
		ft_strcmp(content[6], "NO_CHECKBOARD") != 0))
		return (false);
	return (true);
}

bool	bumpmap_data_check(char *content)
{
	if (!ft_check_extension(content, ".xpm"))
		return (false);
	if (!ft_strchr(content, '/'))
	{
		write(2, "Path must be include /", 39);
		return (false);
	}
	return (true);
}
