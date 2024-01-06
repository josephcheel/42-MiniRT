/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_mac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:44 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/02 09:32:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	key_events(int key, t_field *field)
{
	printf("Entro en keyevents press %x -- %p\n", key, field);
	if (key == XK_CTRL)
	{
		printf("key Ctrl antes %x -->%i\n", key, field->events.key_ctrl_press);
		field->events.key_ctrl_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
		printf("key Ctrl post activado %x -->%i\n",
			key, field->events.key_ctrl_press);
	}
	return (0);
}
