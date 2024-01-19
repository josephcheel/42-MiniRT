/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/09 18:06:05 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_camera_center(t_field *field, char **content)
{
	t_vec3	aux;

	field->camera.center.vx = conv_v_unit(add_vec3(content[2]));
	aux = create_vect(0, 0, 1);
	field->camera.center.vy = prod_vectorial(aux, field->camera.center.vx);
	if (is_zero_vec(field->camera.center.vy))
		field->camera.center.vy = create_vect(0, 1, 0);
	field->camera.center.vz = prod_vectorial(field->camera.center.vx, \
			field->camera.center.vy);
}

int	get_camera(t_field *field, char *line)
{
	char	**content;
	t_vec3	aux;
	double	lambda;

	content = ft_split(line, ' ');
	field->camera.center.pos = add_vec3(content[1]);
	if (ratio_vec3_error(-1, 1, add_vec3(content[2])))
		return (write(2, "Camera normalized Orientation: out of range\n", 44));
	get_camera_center(field, content);
	field->camera.fov = ft_atoi(content[3]);
	if (ratio_int_error(0, 180, field->camera.fov))
		return (write(2, "Camera FOV: out of range\n", 26));
	if (field->camera.fov == 0)
		field->camera.observer = create_vect(LONG_MIN, LONG_MIN, LONG_MIN);
	else
	{
		lambda = -(field->mlx.size_x / 2 - FRAME) * PIXEL \
			/ tan((double)field->camera.fov / 2 / 180 * M_PI);
		aux = prod_cte_vector(lambda, field->camera.center.vx);
		field->camera.observer = suma_vector(field->camera.center.pos, aux);
	}
	ft_array_free(content, ft_array_size(content));
	return (0);
}

int	get_light(t_field *field, char *line)
{
	char	**content;

	content = ft_split(line, ' ');
	field->light = malloc(sizeof(t_light));
	field->light->pos = add_vec3(content[1]);
	field->light->ratio = ft_atof(content[2]);
	if (ratio_double_error(0.0, 1.0, field->light->ratio))
		return (write(2, "Light brightness ratio: out of range\n", 38));
	field->light->color = add_color(content[3]);
	if (rgb_error(field->light->color))
		return (write(2, "Light Color: out of range\n", 27));
	field->light->next = NULL;
	ft_array_free(content, ft_array_size(content));
	return (0);
}

int	get_ambient_light(t_field *field, char *line)
{
	char	**content;

	content = ft_split(line, ' ');
	field->ambient.ratio = ft_atof(content[1]);
	if (ratio_double_error(0.0, 1.0, field->ambient.ratio))
		return (write(2, "Ambiento Ratio: out of range\n", 30));
	field->ambient.color = add_color(content[2]);
	if (rgb_error(field->ambient.color))
		return (write(2, "Ambient Color: out of range\n", 29));
	ft_array_free(content, ft_array_size(content));
	return (0);
}

int	get_devices(t_field *field, char *line)
{
	char	**type;
	int		error;

	error = 0;
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "C") == 0)
	{
		error = get_camera(field, line);
		field->orig_camera = field->camera;
	}
	else if (ft_strcmp(type[0], "L") == 0)
	{
		error = get_light(field, line);
		field->orig_light = ft_clone_light(field->light);
	}
	else if (ft_strcmp(type[0], "A") == 0)
		error = get_ambient_light(field, line);
	ft_array_free(type, ft_array_size(type));
	return (error);
}
