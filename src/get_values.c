/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/03 22:52:27 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Add values from a string with the format "x,y,z" to a t_vec3. (Should I check for maximum and minimum values?)
*/
t_vec3	add_vec3(char *vector3)
{
	t_vec3	vec;
	char **values;

	values = ft_split(vector3, ',');
	if (ft_array_size(values) != 3)
		return (NULL);
	vec.x = ft_atoi(values[0]);
	vec.y = ft_atoi(values[1]);
	vec.z = ft_atoi(values[2]);
	return (vec);
}

void	get_camera(t_field *field, char *line)
{
	char **content;
	content = ft_split(line, ' ');

	field->camera.pos = add_vec3(content[1]);
	field->camera.orientation = add_vec3(content[2]);
	field->camera.fov = ft_atoi(content[3]);
}
void	get_light(t_field *field, char *line)
{
	char **content;
	content = ft_split(line, ' ');
	
	// field->light.pos = add_vec3(content[1]);
	// field->light.orientation = add_vec3(content[2]);
	// field->light.fov = ft_atoi(content[3]);
	// field->light.next = NULL;
}

void	get_ambient_light(t_field *field, char *line)
{

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
}

// void	get_geom(t_field *field, char *line)
// {

// }