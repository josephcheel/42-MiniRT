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

t_vec3 calculate_ray_direction(t_vec3 camPos, t_vec3 imgPoint) {
	t_vec3 rayDir;
	rayDir.x = imgPoint.x - camPos.x;
	rayDir.y = imgPoint.y - camPos.y;
	rayDir.z = imgPoint.z - camPos.z;
	return (rayDir);
}

double calculate_distance_to_screen(int fov)
{
	double fov_rad;
	
	// Pasamos el fov a radianes
	fov_rad = fov * M_PI / 180.0;
	// Calcular la Distancia focal
	double distanciaFocal = 1 / tan(fov_rad / 2);

	 // Cálculo de la magnificación angular
    double magnificacionAngular = atan(WIN_X * WIN_Y * PIXEL / (2 * distanciaFocal));

    // Cálculo de la distancia entre la cámara y la pantalla
    double distanciaCamaraPantalla = WIN_X * WIN_Y * PIXEL / (2 * tan(magnificacionAngular));
	return (distanciaCamaraPantalla);
}

// calculate_point(t_field *field, int x, int y)
// {
	
// 	field->camera.pos - WIN_X * WIN_Y * PIXEL 
// }


void create_field_vectors(t_field *field)
{
	int			i;
	int			j;
	t_vec_pos	*aux;

	aux = (t_vec_pos *) malloc ((WIN_X * WIN_Y) * sizeof(t_vec_pos));
	i = -1;
	j = 0;
	printf("DISTANCIA SCREEN %f\n", calculate_distance_to_screen(field->camera.fov));

	while (++i < WIN_X && j < WIN_Y)
	{
		
		if(i == WIN_X)
		{
			i = -1;
			// aux[i].pt = calculate_point(field, x, y)
			aux[i].v = calculate_ray_direction(field->camera.pos, field->camera.field_vectors[j].pt);
			j++;
		}
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
	aux = add_vec3(content[2]);
	field->camera.orientation = div_cte_vector(modulo_vector(aux), aux);
	aux = create_vect(0, 0, 1);
	aux = prod_vectorial(field->camera.orientation, aux);
	if (is_zero_vec(aux))
		field->camera.orientation2 = create_vect(0, 1, 0);
	else
		field->camera.orientation2 =  div_cte_vector(modulo_vector(aux), aux);
	field->camera.fov = ft_atoi(content[3]);
	lambda = - WIN_X * PIXEL / tan(field->camera.fov / 2);
	aux = prod_cte_vector(lambda, field->camera.orientation);
	field->camera.observer = suma_vector(field->camera.pos, aux);
	ft_array_free(content, ft_array_size(content));
	create_field_vectors(field);
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
