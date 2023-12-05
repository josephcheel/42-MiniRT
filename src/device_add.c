/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	get_camera(t_field *field, char *line)
{
	char **content;
	content = ft_split(line, ' ');

	field->camera.pos = add_vec3(content[1]);
	field->camera.orientation = add_vec3(content[2]);
	field->camera.fov = ft_atoi(content[3]);
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
	
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "C") == 0)
		get_camera(field, line);
	else if (ft_strcmp(type[0], "L") == 0)
		get_light(field, line);
	else if (ft_strcmp(type[0], "A") == 0)
		get_ambient_light(field, line);
	ft_array_free(type, ft_array_size(type));
}
