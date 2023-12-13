/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/05 18:38:38 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void create_field_vectors(t_field *field)
{
	int			i;
	int			j;
	t_vec_pos	*aux;

	aux = (t_vec_pos *) malloc ((WIN_X * WIN_Y) * sizeof(t_vec_pos));
	i = -1;
	j = 0;
	while (++i < WIN_X && j < WIN_Y)
	{
		
		if(i == WIN_X)
		{
			i = -1;
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
