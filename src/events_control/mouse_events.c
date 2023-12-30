/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:50:25 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/26 15:50:58 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	mouse_events_pre(int mouse, int x, int y, t_field *field)
{
	if (mouse == MOUSE_BTN_ROT_UP)
	{
		if (field->events.key_ctrl_press)
			field->light->pos = suma_vector(field->light->pos, \
				create_vect(-1, 0, 0));
	}
	else if (mouse == MOUSE_BTN_ROT_DW)
	{
		if (field->events.key_ctrl_press)
			field->light->pos = suma_vector(field->light->pos, \
				create_vect(1, 0, 0));
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
	t_vec3	v;

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
		field->events.btn_left_presd = 0;
		v = resta_vector(field->aux, create_vect(0, x, y));
		field->light->pos = suma_vector(field->light->pos, v);
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
