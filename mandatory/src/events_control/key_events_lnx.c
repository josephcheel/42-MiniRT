/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_lnx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:44 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/11 19:39:56 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	key_events_press(int key, t_field *field)
{
	printf("Entro en keyevents press %x -- %p\n", key, field);
	if (key == XK_CTRL)
	{
		field->events.key_ctrl_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
	}
	else if (key == XK_ALT)
	{
		field->events.key_alt_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
	}
	else if (key == XK_SHIFT)
	{
		field->events.key_shift_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
	}
	return (0);
}

int	key_events_release(int key, t_field *field)
{
	if (key == XK_ESC)
		ft_close(field);
	else if (key == XK_CTRL)
	{
		field->events.key_ctrl_press = 0;
		dump_mem_2_scr(field);
	}
	else if (key == XK_ALT)
	{
		field->events.key_alt_press = 0;
		dump_mem_2_scr(field);
	}
	else if (key == XK_SHIFT)
	{
		field->events.key_shift_press = 0;
		dump_mem_2_scr(field);
	}
	return (0);
}
