/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/15 23:27:17 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	get_camera(t_field *field, char *line)
{
	char **content;
	t_vec3	aux;
	double	lambda;

	content = ft_split(line, ' ');
	field->camera.center.pos = add_vec3(content[1]);
	field->camera.center.vx = conv_v_unit(add_vec3(content[2]));
	aux = create_vect(0, 0, 1);
	field->camera.center.vy = prod_vectorial(aux, field->camera.center.vx);
	if (is_zero_vec(field->camera.center.vy))
		field->camera.center.vy = create_vect(0, 1, 0);
	field->camera.center.vz = prod_vectorial(field->camera.center.vx, \
			field->camera.center.vy);
	field->camera.fov = ft_atoi(content[3]);
	if (field->camera.fov == 0)
	{
		field->camera.observer = create_vect(LONG_MIN, LONG_MIN, LONG_MIN);
	}
	else
	{
		lambda = - (field->mlx.size_x - FRAME) * PIXEL / 2 / tan(field->camera.fov / 2);
		aux = prod_cte_vector(lambda, field->camera.center.vx);
		field->camera.observer = suma_vector(field->camera.center.pos, aux);
	}
	ft_array_free(content, ft_array_size(content));
}

void	get_light(t_field *field, char *line)
{
	char **content;
	content = ft_split(line, ' ');
	
	field->light = malloc(sizeof(t_light));
	field->light->pos = add_vec3(content[1]);
	field->light->ratio = ft_atof(content[2]);
	field->light->color = add_color(content[3]);
	field->light->next = NULL;
	ft_array_free(content, ft_array_size(content));
}

void	get_ambient_light(t_field *field, char *line)
{
	char **content;
	content = ft_split(line, ' ');
	
	field->ambient.ratio = ft_atof(content[1]);
	field->ambient.color = add_color(content[2]);
	ft_array_free(content, ft_array_size(content));
}

void	get_devices(t_field *field, char *line)
{
	char **type;
	
	// DEBUG
//	printf("es un device -- $%s$\n", line);
	
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "C") == 0)
		get_camera(field, line);
	else if (ft_strcmp(type[0], "L") == 0)
		get_light(field, line);
	else if (ft_strcmp(type[0], "A") == 0)
		get_ambient_light(field, line);
	ft_array_free(type, ft_array_size(type));
}
