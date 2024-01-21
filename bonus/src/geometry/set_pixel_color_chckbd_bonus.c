/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_chckbd_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:55:29 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 11:57:02 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_color	set_pixel_color_chckdb(t_int_pts vp, t_field *field)
{
	int		a;
	int		b;
	int		c;

	a = ceil(round(vp.pt.pt.x) / (round(field->chckbd.size)));
	b = ceil(round(vp.pt.pt.y) / (round(field->chckbd.size)));
	c = ceil(round(vp.pt.pt.z) / (round(field->chckbd.size)));
	if (((int)a + (int)b + (int)c) % 2 == 0)
		return (field->chckbd.c1);
	else
		return (field->chckbd.c2);
}
