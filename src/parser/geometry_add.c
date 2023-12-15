/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/05 18:38:10 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_geom	*get_sphere(char *line)
{
	t_geom	*sphere;
	char	**content;
	
	content = ft_split(line, ' ');
	sphere = malloc(sizeof(t_geom));
	sphere->type = SPHERE;
	sphere->vp.pt = add_vec3(content[1]);
	sphere->vp.v = create_vect(0, 0, 0);
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
	plane->vp.pt = add_vec3(content[1]);
	plane->vp.v = conv_vect_unit(add_vec3(content[2]));
	plane->color = add_color(content[3]);
	plane->next = NULL;
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
	cylinder->vp.pt = add_vec3(content[1]);
	cylinder->vp.v = conv_vect_unit(add_vec3(content[2]));
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

	// DEBUG
	printf ("es un a geometria -- $%s$\n", line);
	
	temp = NULL;
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "sp") == 0)
		temp = get_sphere(line);
	else if (ft_strcmp(type[0], "pl") == 0)
		temp = get_plane(line);
	else if (ft_strcmp(type[0], "cy") == 0)
		temp = get_cylinder(line);
	ft_geomadd_back(&field->geom, temp);
	ft_array_free(type, ft_array_size(type));
}