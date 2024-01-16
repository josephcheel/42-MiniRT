/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ratios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:12:21 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 02:39:23 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	ratio_vec3_error(int min, int max, t_vec3 vector)
{
	if (ratio_double_error(min, max, vector.x)
		|| ratio_double_error(min, max, vector.y)
		|| ratio_double_error(min, max, vector.z))
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

bool	ft_check_vect3_ratio(char *content, double min, double max)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(content, ',');
	while (split[i] != NULL)
	{
		if (ratio_double_error(min, max, ft_atof(split[i])))
		{
			ft_array_free(split, ft_array_size(split));
			return (false);
		}
		i++;
	}
	ft_array_free(split, ft_array_size(split));
	return (true);
}

bool	ft_check_rgb_ratio(char *content)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(content, ',');
	while (split[i] != NULL)
	{
		if (ft_atof(split[i]) < 0 || ft_atof(split[i]) > 255)
		{
			ft_array_free(split, ft_array_size(split));
			return (false);
		}
		i++;
	}
	ft_array_free(split, ft_array_size(split));
	return (true);
}
