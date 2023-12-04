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

t_geom	*get_sphere(char *line)
{
	t_geom	*sphere;
	char	**content;
	
	content = ft_split(line, ' ');
	
	sphere = malloc(sizeof(t_geom));
	sphere->type = SPHERE;
	sphere->pt1 = add_vec3(content[1]);
	sphere->r = ft_atof(content[2]) / 2;
	sphere->color = add_color(content[3]);
	sphere->next = NULL;
	ft_array_free(content, ft_array_size(content));
	return (sphere);
}

t_geom	*get_plane(char *line)
{
	t_geom	*plane;
	char **content;
	
	content = ft_split(line, ' ');
	plane = malloc(sizeof(t_geom));
	plane->type = PLANE;
	plane->pt1 = add_vec3(content[1]);
	plane->direction = add_vec3(content[2]);
	plane->color = add_color(content[3]);
	plane->next = NULL;
	// field->geom->
	ft_array_free(content, ft_array_size(content));
	return (plane);
}

t_geom	*get_cylinder( char *line)
{
	t_geom	*cylinder;
	char	**content;
	
	
	content = ft_split(line, ' ');

	cylinder = malloc(sizeof(t_geom));
	cylinder->type = CYLINDER;
	cylinder->pt1 = add_vec3(content[1]);
	cylinder->direction = add_vec3(content[2]);
	cylinder->r = ft_atof(content[3]) / 2;
	cylinder->height = ft_atof(content[4]);
	cylinder->color = add_color(content[5]);
	cylinder->next = NULL;
	ft_array_free(content, ft_array_size(content));
	return (cylinder);
}

void	get_geom(t_field *field, char *line)
{
	t_geom *temp;
	char **type;

	temp = NULL;
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "sp") == 0)
		temp = get_sphere(line);
	else if (ft_strcmp(type[0], "pl") == 0)
		temp = get_plane(line);
	else if (ft_strcmp(type[0], "cy") == 0)
		temp = get_cylinder(line);
	ft_geomadd_back(&field->geom, temp);
}