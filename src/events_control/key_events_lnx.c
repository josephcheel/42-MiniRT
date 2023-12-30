/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:44 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/26 15:51:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	key_events_press(int key, t_field *field)
{
	printf("Entro en keyevents press %x -- %p\n", key, field);
	if (key == XK_CTRL)
	{
		printf("key Ctrl antes %x -->%i\n", key, field->events.key_ctrl_press);
		field->events.key_ctrl_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
		printf("key Ctrl post activado %x -->%i\n", \
			key, field->events.key_ctrl_press);
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
	return (0);
}
