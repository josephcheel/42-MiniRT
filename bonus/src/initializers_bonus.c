/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_bonus.h"

void	init_mlx(t_field *field)
{
	field->mlx.frame = FRAME;
	field->mlx.size_x = WIN_X;
	field->mlx.size_y = WIN_Y;
	field->mlx.mlx = mlx_init();
	field->mlx.win = mlx_new_window(field->mlx.mlx, \
			field->mlx.size_x = WIN_X, field->mlx.size_y, WIN_NAME);
	field->mlx.img = mlx_new_image(field->mlx.mlx, \
			field->mlx.size_x, field->mlx.size_y);
	mlx_hook(field->mlx.win, EVENT_KEY_PRESS, 1L << MASK_KEY_PRESS, \
			key_events_press, (t_field *)field);
	mlx_hook(field->mlx.win, EVENT_KEY_RELEASE, 1L << MASK_KEY_RELEASE, \
			key_events_release, (t_field *)field);
	mlx_hook(field->mlx.win, EVENT_DESTROY_NOTIFY, 1L << MASK_DESTROY_NOTIFY, \
			ft_close, (t_field *)field);
	mlx_hook(field->mlx.win, EVENT_BUTTON_PRESS, 1L << MASK_BUTTON_PRESS, \
			mouse_events_pre, (t_field *)field);
	mlx_hook(field->mlx.win, EVENT_BUTTON_RELEASE, 1L << MASK_BUTTON_RELEASE, \
			mouse_events_rel, (t_field *)field);
}

//	mlx_hook(field->mlx.win, EVENT_MOTION_NOTIFY, 1L << MASK_MOTION_NOTIFY,
//			 mouse_events_mov, (t_field *)field);

static void	init_events(t_field *field)
{
	field->events.btn_cent_presd = 0;
	field->events.btn_left_presd = 0;
	field->events.btn_rght_presd = 0;
	field->events.key_ctrl_press = 0;
	field->events.key_alt_press = 0;
	field->events.key_shift_press = 0;
}

t_field	*init_field(void)
{
	t_field	*field;

	field = (t_field *)malloc(sizeof(t_field));
	if (!field)
		return (NULL);
	field->geom = NULL;
	field->light = NULL;
	init_events(field);
	return (field);
}

t_field	*initializer(char *av)
{
	t_field	*field;

	field = init_field();
	if (!field)
		return (NULL);
	init_mlx(field);
	if (read_file(av, field))
		return (NULL);
	def_vector_sense(field);
	return (field);
}
