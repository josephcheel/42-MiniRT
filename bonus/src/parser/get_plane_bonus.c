/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_geom	*get_plane(char *line, t_field *field)
{
	t_geom	*plane;
	char	**content;

	content = ft_split(line, ' ');
	plane = malloc(sizeof(t_geom));
	plane->type = PLANE;
	plane->vp.pt = add_vec3(content[1]);
	plane->vp.v = conv_v_unit(add_vec3(content[2]));
	plane->color = add_color(content[3]);
	plane->sense = 1;
	plane->next = NULL;
	plane->bumpmap.is_bumpmap = false;
	if (ft_array_size(content) == 5)
		plane->bumpmap = get_bumpmap(content[4], field);
	ft_array_free(content, ft_array_size(content));
	return (plane);
}
