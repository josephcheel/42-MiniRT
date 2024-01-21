/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_chckbd_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:55:29 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 03:19:52 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_color	set_pixel_color_chckdb(t_int_pts vp, t_field *field)
{
	int		a;
	int		b;
	int		c;

	a = floor((int)(vp.pt.pt.x) / ((field->chckbd.size)));
	b = floor((int)(vp.pt.pt.y) / ((field->chckbd.size)));
	c = floor((int)(vp.pt.pt.z) / ((field->chckbd.size)));
	if (((int)a + (int)b + (int)c) % 2 == 0)
		return (field->chckbd.c1);
	else
		return (field->chckbd.c2);
}
