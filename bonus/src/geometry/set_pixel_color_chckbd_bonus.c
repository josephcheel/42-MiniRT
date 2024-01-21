/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_chckbd_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:55:29 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 02:16:13 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_color	set_pixel_color_chckdb(t_int_pts vp, t_field *field)
{
	double		a;
	double		b;
	double		c;

	a = round((vp.pt.pt.x)) / ((field->chckbd.size) / 2);
	b = round((vp.pt.pt.y)) / ((field->chckbd.size) / 2);
	c = round((vp.pt.pt.z)) / ((field->chckbd.size) / 2);
	if (((int)a + (int)b + (int)c) % 2 == 0)
		return (field->chckbd.c1);
	else
		return (field->chckbd.c2);
}
