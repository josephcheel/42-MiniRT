/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triang_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_geom	*get_triang(char *line, t_field *field)
{
	t_geom	*triang;
	char	**content;
	t_vec3	aux[2];

	content = ft_split(line, ' ');
	triang = malloc(sizeof(t_geom));
	triang->type = TRIANGLE;
	triang->vp.pt = add_vec3(content[1]);
	triang->vp1.pt = add_vec3(content[2]);
	triang->vp2.pt = add_vec3(content[3]);
	aux[0] = resta_vector(triang->vp1.pt, triang->vp.pt);
	aux[1] = resta_vector(triang->vp2.pt, triang->vp.pt);
	triang->vp.v = conv_v_unit(prod_vectorial(aux[0], aux[1]));
	triang->color = add_color(content[4]);
	triang->sense = 1;
	triang->next = NULL;
	triang->bumpmap.is_bumpmap = false;
	if (ft_array_size(content) == 6)
		triang->bumpmap = get_bumpmap(content[5], field);
	ft_array_free(content, ft_array_size(content));
	return (triang);
}
