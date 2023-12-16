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

t_vec3 calculate_ray_direction(t_vec3 camPos, t_vec3 imgPoint)
{
	t_vec3	raydir;
	raydir.x = imgPoint.x - camPos.x;
	raydir.y = imgPoint.y - camPos.y;
	raydir.z = imgPoint.z - camPos.z;
	return (raydir);
}

t_vec3	get_screen_center(t_field *field)
{
	t_vec3 center;

	center = create_vect(WIN_X/2, WIN_Y/2, calculate_distance_to_screen(field->camera.fov) * 100);
	return (center);
}

void create_field_vectors(t_field *field)
{
	int			x;
	int			y;
	t_vec_pos	*aux;

	aux = (t_vec_pos *) malloc ((WIN_X * WIN_Y) * sizeof(t_vec_pos));
	x = 0;
	y = 0;
	
	// aux[(WIN_X * WIN_Y) / 2].pt = get_screen_center(field);
	while (x <= WIN_X && y <= WIN_Y)
	{
		
		aux[x * y].pt = calculate_point(field, x, y);
		//aux[i].v = calculate_ray_direction(field->camera.pos, field->camera.field_vectors[j].pt);
		if(x % WIN_X == 0)
		{
			x = 0;
			y++;
		}
		x++;
		
	}
	field->camera.field_vectors = aux;
}

void	get_camera(t_field *field, char *line)
{
	char **content;
	t_vec3	aux;
	double	lambda;

	content = ft_split(line, ' ');
	field->camera.pos = add_vec3(content[1]);
	field->camera.orient_x = conv_vect_unit(add_vec3(content[2]));
	aux = create_vect(0, 0, 1);
	field->camera.orient_y = prod_vectorial(aux, field->camera.orient_x);
	if (is_zero_vec(field->camera.orient_y))
		field->camera.orient_y = create_vect(0, 1, 0);
	field->camera.orient_z = prod_vectorial(field->camera.orient_x, field->camera.orient_y);
	field->camera.fov = ft_atoi(content[3]);
	lambda = - (field->mlx.size_x - FRAME) * PIXEL / 2 / tan(field->camera.fov / 2);
	aux = prod_cte_vector(lambda, field->camera.orient_x);
	field->camera.observer = suma_vector(field->camera.pos, aux);
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
	printf("es un device -- $%s$\n", line);
	
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "C") == 0)
		get_camera(field, line);
	else if (ft_strcmp(type[0], "L") == 0)
		get_light(field, line);
	else if (ft_strcmp(type[0], "A") == 0)
		get_ambient_light(field, line);
	ft_array_free(type, ft_array_size(type));
}
