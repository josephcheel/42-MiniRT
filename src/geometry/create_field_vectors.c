/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void create_field_vectors(t_field *field)
{
	int			i[2];
	t_vec_pos	*aux;
	t_vec3		tmp[3];

	i[0] = -1;
	i[1] = 0;
	aux = (t_vec_pos *) malloc(((field->mlx.size_x - FRAME * 2) * \
			(field->mlx.size_y - FRAME * 2)) * sizeof(t_vec_pos));
	if (!aux)
		return ;
	while (++i[0] < field->mlx.size_x - FRAME * 2 && \
			i[1] < field->mlx.size_y - FRAME * 2)
	{
		tmp[1] = prod_cte_vector((field->mlx.size_x/2 - FRAME - i[0]) * PIXEL, \
					field->camera.orient_x);
		tmp[2] = prod_cte_vector((field->mlx.size_y/2 - FRAME - i[1]) * PIXEL, \
					field->camera.orient_y);
		tmp[0] = suma_vector(tmp[1], tmp[2]);
		aux[i[0] + i[1] * (field->mlx.size_x - FRAME * 2)].pt = \
				suma_vector(tmp[0], field->camera.pos);  
		aux[i[0] + i[1] * (field->mlx.size_x - FRAME * 2)].v = \
				resta_vector(aux[i[0] + i[1] * (field->mlx.size_x - FRAME * 2)].pt, 
								field->camera.observer);  
		aux[i[0] + i[1] * (field->mlx.size_x - FRAME * 2)].v = \
				conv_vect_unit(aux[i[0] + i[1] * (field->mlx.size_x - FRAME * 2)].v);
		if (i[0] == field->mlx.size_x - FRAME * 2)
		{
			i[0] = -1;
			i[1]++;
		}	
	}
	field->camera.field_vectors = aux;
}
