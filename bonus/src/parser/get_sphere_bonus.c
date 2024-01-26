/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_geom	*get_sphere(char *line, t_field *field)
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
	sphere->sense = 1;
	sphere->next = NULL;
	sphere->bumpmap.is_bumpmap = false;
	if (ft_array_size(content) == 5)
		sphere->bumpmap = get_bumpmap(content[4], field);
	ft_array_free(content, ft_array_size(content));
	return (sphere);
}
