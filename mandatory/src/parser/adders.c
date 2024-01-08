/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/02 01:50:34 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/*
** Add values from a string with the format "x,y,z" to a t_vec3.
*/
t_vec3	add_vec3(char *vector3)
{
	t_vec3	vec;
	char	**values;

	values = ft_split(vector3, ',');
	if (ft_array_size(values) != 3)
		return ((t_vec3){0});
	vec.x = ft_atof(values[0]);
	vec.y = ft_atof(values[1]);
	vec.z = ft_atof(values[2]);
	if (!vec.x && !vec.y && !vec.z)
		vec.x = 1;
	ft_array_free(values, ft_array_size(values));
	return (vec);
}

/*
** Add values from a string with the format "r,g,b" to a t_color.
*/
t_color	add_color(char *color)
{
	t_color	rgba;
	char	**values;

	values = ft_split(color, ',');
	if (ft_array_size(values) != 3)
		return ((t_color){0});
	rgba.r = ft_atoi(values[0]);
	rgba.g = ft_atoi(values[1]);
	rgba.b = ft_atoi(values[2]);
	rgba.a = 0;
	ft_array_free(values, ft_array_size(values));
	return (rgba);
}
