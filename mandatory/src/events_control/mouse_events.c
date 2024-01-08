/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:50:25 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/03 16:29:12 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static void	zoom(int cte, t_field *field)
{
	if (field->events.key_ctrl_press)
		field->light->pos = suma_vector(field->light->pos, \
			prod_cte_vector(cte, field->camera.center.vx));
	else if (field->events.key_alt_press)
	{
		field->camera.center.pos = suma_vector(field->camera.center.pos, \
			prod_cte_vector(cte, field->camera.center.vx));
	}
}

static void	displ(t_field *field, int x, int y)
{
	t_vec3	v;

	x = x - field->mlx.size_x / 2;
	y = field->mlx.size_y / 2 - y;
	if (field->events.key_ctrl_press)
	{
		field->events.btn_left_presd = 0;
		v = resta_vector(field->aux, create_vect(0, x, y));
		v = suma_vector(prod_cte_vector(v.y, field->camera.center.vy), \
				prod_cte_vector(v.z, field->camera.center.vz));
		field->light->pos = suma_vector(field->light->pos, v);
	}
	else if (field->events.key_alt_press)
	{
		field->events.btn_left_presd = 0;
		v = resta_vector(create_vect(0, x, y), field->aux);
		v = resta_vector(prod_cte_vector(v.y, field->camera.center.vy), \
				prod_cte_vector(v.z, field->camera.center.vz));
		field->camera.center.pos = suma_vector(field->camera.center.pos, v);
	}
}

static void	cam_rotate(t_field *field, int x, int y)
{
	t_vec3	v_rot[3];
	double	ang_rot;
	double	aux;

	x = x - field->mlx.size_x / 2;
	y = field->mlx.size_y / 2 - y;
	if (sqrt(pow(x, 2) + pow(y, 2)) > ROT_SPH)
	{
		v_rot[0] = conv_v_unit(field->aux);
		v_rot[1] = create_vect(0, x, y);
		v_rot[2] = conv_v_unit(prod_vectorial(v_rot[0], v_rot[1]));
		ang_rot = acos(prod_escalar(conv_v_unit(field->aux), \
					conv_v_unit(create_vect(0, x, y))));
	}
	else
	{
		aux = sqrt(pow(ROT_SPH, 2) - pow(x, 2) - pow(y, 2));
		v_rot[1] = conv_v_unit(create_vect(aux, x, y));
		aux = sqrt(pow(ROT_SPH, 2) - pow(field->aux.y, 2) - pow(field->aux.z, 2));
		v_rot[0] = conv_v_unit(create_vect(aux, field->aux.y, field->aux.z));
		v_rot[2] = conv_v_unit(prod_vectorial(v_rot[1], v_rot[0]));
		ang_rot = acos(prod_escalar(v_rot[1], v_rot[0]));
		field->camera.center.vx = rotate_vector(field->camera.center.vx, v_rot[2], ang_rot);
	}
	field->camera.center.vy = rotate_vector(field->camera.center.vy, v_rot[2], ang_rot);
	field->camera.center.vz = rotate_vector(field->camera.center.vz, v_rot[2], ang_rot);
}

int	mouse_events_pre(int mouse, int x, int y, t_field *field)
{
	if (mouse == MOUSE_BTN_ROT_UP)
	{
		zoom(-10, field);
	}
	else if (mouse == MOUSE_BTN_ROT_DW)
	{
		zoom(10, field);
	}
	else if (mouse == MOUSE_BTN_MIDDLE)
		field->events.btn_cent_presd = 1;
	else if (mouse == MOUSE_BTN_RIGHT)
		field->events.btn_rght_presd = 1;
	else if (mouse == MOUSE_BTN_LEFT)
	{
		print_pixel_values(x, y, field);
		field->events.btn_left_presd = 1;
		x = x - field->mlx.size_x / 2;
		y = field->mlx.size_y / 2 - y;
		field->aux = create_vect(0, x, y);
	}
	return (0);
}

int	mouse_events_rel(int mouse, int x, int y, t_field *field)
{
	if (mouse == MOUSE_BTN_ROT_UP)
		printf("Button rotation up--%i -- %i\n", x, y);
	else if (mouse == MOUSE_BTN_MIDDLE)
	{
		printf("Middle button released--%i -- %i\n", x, y);
		field->events.btn_cent_presd = 0;
	}
	else if (mouse == MOUSE_BTN_ROT_DW)
		printf("Button rotation DW--%i -- %i\n", x, y);
	else if (mouse == MOUSE_BTN_RIGHT)
		field->events.btn_rght_presd = 0;
	if (mouse == MOUSE_BTN_LEFT && x > 0 && y > 0)
	{
		if (field->events.key_alt_press || field->events.key_ctrl_press)
			displ(field, x, y);
		if (field->events.key_shift_press)
			cam_rotate(field, x, y);
	}
	return (0);
}

int	mouse_events_mov(int x, int y, t_field *field)
{
	printf("Left movement mouse--%i -- %i\n", x, y);
	if (field->events.btn_left_presd && field->events.key_ctrl_press)
	{
		printf("Entro en mouse events move %i -- %i -- %p\n", \
			field->events.btn_left_presd, field->events.key_ctrl_press, field);
	}
	return (0);
}
