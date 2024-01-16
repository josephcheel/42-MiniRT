/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_rot_zoom_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:28:46 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

void	zoom(int cte, t_field *field)
{
	if (field->events.key_ctrl_press)
	{
		field->light->pos = suma_vector(field->light->pos, \
			prod_cte_vector(cte, field->camera.center.vx));
		def_vector_sense(field);
	}
	else if (field->events.key_alt_press)
	{
		field->camera.center.pos = suma_vector(field->camera.center.pos, \
			prod_cte_vector(cte, field->camera.center.vx));
		field->camera.observer = suma_vector(field->camera.observer, \
			prod_cte_vector(cte, field->camera.center.vx));
	}
}

void	displ(t_field *field, int x, int y)
{
	t_vec3	v;

	x = x - field->mlx.size_x / 2;
	y = field->mlx.size_y / 2 - y;
	if (field->events.key_ctrl_press)
	{
		field->events.btn_left_presd = 0;
		v = resta_vector(field->aux, create_vect(0, x, y));
		v = resta_vector(prod_cte_vector(v.y, field->camera.center.vy), \
				prod_cte_vector(v.z, field->camera.center.vz));
		field->light->pos = suma_vector(field->light->pos, v);
		def_vector_sense(field);
	}
	else if (field->events.key_alt_press)
	{
		field->events.btn_left_presd = 0;
		v = resta_vector(create_vect(0, x, y), field->aux);
		v = resta_vector(prod_cte_vector(v.y, field->camera.center.vy), \
				prod_cte_vector(v.z, field->camera.center.vz));
		field->camera.center.pos = suma_vector(field->camera.center.pos, v);
		field->camera.observer = suma_vector(field->camera.observer, v);
	}
}

static t_vec3	*create_vect_rot(int type, t_field *field, int x, int y)
{
	t_vec3	*v_rot;
	double	aux;

	v_rot = malloc(sizeof(t_vec3) * 3);
	if (type == 1)
	{
		v_rot[0] = conv_v_unit(field->aux);
		v_rot[1] = create_vect(0, x, y);
		v_rot[2] = conv_v_unit(prod_vectorial(v_rot[0], v_rot[1]));
	}
	else if (type == 2)
	{
		aux = sqrt(pow(ROT_SPH, 2) - pow(x, 2) - pow(y, 2));
		v_rot[1] = conv_v_unit(create_vect(aux, x, y));
		aux = sqrt(pow(ROT_SPH, 2) - \
		pow(field->aux.y, 2) - pow(field->aux.z, 2));
		v_rot[0] = conv_v_unit(create_vect(aux, field->aux.y, field->aux.z));
		v_rot[2] = conv_v_unit(prod_vectorial(v_rot[1], v_rot[0]));
	}
	return (v_rot);
}

static void	rotate_vect_yz(t_vec3 *v_rot, t_field *field, double ang_rot)
{
	field->camera.center.vy = \
	rotate_vector(field->camera.center.vy, v_rot[2], ang_rot);
	field->camera.center.vz = \
	rotate_vector(field->camera.center.vz, v_rot[2], ang_rot);
	free(v_rot);
}

void	cam_rotate(t_field *field, int x, int y)
{
	t_vec3	*v_rot;
	double	ang_rot;

	x = x - field->mlx.size_x / 2;
	y = field->mlx.size_y / 2 - y;
	if (sqrt(pow(x, 2) + pow(y, 2)) > ROT_SPH)
	{
		v_rot = create_vect_rot(1, field, x, y);
		ang_rot = acos(prod_escalar(conv_v_unit(field->aux), \
					conv_v_unit(create_vect(0, x, y))));
	}
	else
	{
		v_rot = create_vect_rot(2, field, x, y);
		ang_rot = acos(prod_escalar(v_rot[1], v_rot[0]));
		field->camera.center.vx = \
		rotate_vector(field->camera.center.vx, v_rot[2], ang_rot);
		v_rot[0] = resta_vector(field->camera.center.pos, \
					field->camera.observer);
		v_rot[1] = rotate_vector(v_rot[0], v_rot[2], ang_rot);
		field->camera.observer = \
				suma_vector(field->camera.center.pos, v_rot[1]);
	}
	rotate_vect_yz(v_rot, field, ang_rot);
}
