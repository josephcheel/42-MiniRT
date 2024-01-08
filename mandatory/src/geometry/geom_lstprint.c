/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_lstprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 02:06:01 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/03 16:30:33 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_print_geometry_full(t_geom *head)
{
	t_geom	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		ft_print_geometry_node(temporary);
		temporary = temporary->next;
	}
	printf("\n");
}

void	ft_print_geometry_node(t_geom *node)
{
	if (node)
	{
		printf("\n\x1b[32;01m=====PRINT GEOMETRY NODE=====\x1b[0m\n");
		printf("TYPE\t\t\t\t%u\n", node->type);
		printf("POSITION\t\t\tX %lf Y %lf, Z %lf\n", node->vp.pt.x, node->vp.pt.y, node->vp.pt.z);
		printf("NORMALIZATION DIRECTION \tX %lf Y %lf, Z %lf\n", node->vp.v.x, node->vp.v.y, node->vp.v.z);
		printf("RADIUS\t\t\t\t%lf\n", node->r);
		printf("COLOR\t\t\t\tR %d G %d B %d A %d\n", node->color.r, node->color.g, node->color.b, node->color.a);
		printf("HEIGHT\t\t\t\t%lf\n", node->height);
	}
}

void	ft_print_camera(t_field *field)
{
	printf("\n\x1b[38;5;36m=======CAMERA======\x1b[0m\n");
	//printf("Viewpoint:\t\t\tX %f, Y %f, Z %f\n", field->camera.pos.x, field->camera.pos.y, field->camera.pos.z);
	//printf("Orientation:\t\t\tX %f, Y %f, Z %f\n", field->camera.orient_x, field->camera.orientation.y, field->camera.orientation.z);
	printf("FOV:\t\t\t\t%d\n", field->camera.fov);
}

void	ft_print_light(t_field *field)
{
	printf("\n\x1b[38;5;38m=======LIGHT=======\x1b[0m\n");
	printf("Position:\t\t\tX %f, Y %f, Z %f\n", field->light->pos.x, field->light->pos.y, field->light->pos.z);
	printf("Brightness:\t\t\t%f\n", field->light->ratio);
	printf("Color:\t\t\t\t R %d, G %d, B %d\n", field->light->color.r, field->light->color.g, field->light->color.b);
}

void	ft_print_ambient(t_field *field)
{
	printf("\n\x1b[38;5;60m=======AMBIENT=====\x1b[0m\n");
	printf("Brightness:\t\t\t%f\n", field->ambient.ratio);
	printf("Color:\t\t\t\tR %d, G %d, B %d\n", field->ambient.color.r, field->ambient.color.g, field->ambient.color.b);
}
void	ft_print_vector(char *s, t_vec_pos v)
{
	printf("\n%s=======%s=====%s\n", CHR_BLUE, s, RESET);
	printf("Posicion:\tx<%f>\ty<%f>\tz<%f>\n", v.pt.x, v.pt.y, v.pt.z);
	printf("Direccion:\tx<%f>\ty<%f>\tz<%f>\n", v.v.x, v.v.y, v.v.z);
	printf("Direccion:\tr<%d>\tg<%d>\tb<%d>\ta<%d>\n", v.c.r, v.c.g, v.c.b, v.c.a);
}