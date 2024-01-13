/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_vector_sense.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:12:21 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/09 13:15:17 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	get_plane_sense(t_geom *g, t_light *l)
{
	t_vec3	v;

	v = conv_v_unit(resta_vector(l->pos, g->vp.pt));
	if (prod_escalar(v, g->vp.v) < 0)
		return (-1);
	return (1);
}

static int	get_sphere_sense(t_geom *g, t_light *l)
{
	t_vec3	v;

	v = resta_vector(g->vp.pt, l->pos);
	if (modulo_vector(v) < g->r)
		return (-1);
	return (1);
}

static int	get_cyl_sense(t_geom *g, t_light *l)
{
	t_vec3	v[2];
	double	d;

	d = dist_pto_vector(l->pos, g->vp.pt, g->vp.v);
	v[0] = resta_vector(g->vp.pt, l->pos);
	v[1] = suma_vector(prod_cte_vector(g->height, g->vp.pt), g->vp.pt);
	v[1] = resta_vector(v[1], l->pos);
	if (d > g->r)
		return (1);
	else if (prod_escalar(v[0], g->vp.v) > 0 && prod_escalar(v[0], g->vp.v) < 0)
		return (-1);
	return (1);
}

void	def_vector_sense(t_field *field)
{
	t_geom	*ptr;

	ptr = field->geom;
	while (ptr)
	{
		if (ptr->type == PLANE)
			ptr->sense = get_plane_sense(ptr, field->light);
		else if (ptr->type == SPHERE)
			ptr->sense = get_sphere_sense(ptr, field->light);
		else
			ptr->sense = get_cyl_sense(ptr, field->light);
		ptr = ptr->next;
	}
}
//if (ptr.type == CYLINDER)//