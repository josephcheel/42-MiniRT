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

	if (field->events.key_ctrl_press)
	{
		field->events.btn_left_presd = 0;
		v = suma_vector(prod_cte_vector(x, field->camera.center.vy), \
				prod_cte_vector(y, field->camera.center.vz));
		v = resta_vector(field->aux, v);
		field->light->pos = suma_vector(field->light->pos, v);
	}
	else if (field->events.key_alt_press)
	{
		field->events.btn_left_presd = 0;
		v = suma_vector(prod_cte_vector(x, field->camera.center.vy), \
				prod_cte_vector(y, field->camera.center.vz));
		v = resta_vector(v, field->aux);
		field->camera.center.pos = suma_vector(field->camera.center.pos, v);
	}
}

static void	cam_rotate(void)
{
	printf("Axis rotation to be implemented\n");
}
/*
static void cam_rotate(t_field *field, int x, int y)
{
	t_vec3 v1;
	t_vec3 v2;
	double	modulo
	double	angulo[2];

	field->events.btn_left_presd = 0;
	v = create_vect(0, field->mlx.size_x, field->mlx.size_y);
	v = resta_vector(field->aux, v)
	if modulo_vector (field->aux > )
		angulo[0] = modulo_vector(field->aux);

	v = suma_vector(prod_cte_vector(x, field->camera.center.vy),
					prod_cte_vector(y, field->camera.center.vz));
	v = resta_vector(v, field->aux);
	field->camera.center.pos = suma_vector(field->camera.center.pos, v);
}
*/

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
		field->events.btn_left_presd = 1;
		field->aux = create_vect(0, x, y);
		print_pixel_values(x, y, field);
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
			cam_rotate();
		// cam_rotate(field, x, y);
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
