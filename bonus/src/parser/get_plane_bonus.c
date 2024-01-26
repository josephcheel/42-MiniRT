/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/26 18:18:46 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_optional_values(t_field *field, t_geom *plane, char **content)
{
	if (ft_array_size(content) == 5)
	{
		if (ft_strcmp(content[4], "NO_CHECKBOARD") == 0)
			plane->is_chckbd = false;
		else
			plane->bumpmap = get_bumpmap(content[4], field);
	}
	if (ft_array_size(content) == 6)
	{
		if (ft_strcmp(content[5], "NO_CHECKBOARD") == 0)
			plane->is_chckbd = false;
		else
			plane->bumpmap = get_bumpmap(content[5], field);
	}
}

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
	plane->is_chckbd = true;
	get_optional_values(field, plane, content);
	ft_array_free(content, ft_array_size(content));
	return (plane);
}
