/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_bumpmap_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:06:02 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 15:49:47 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_color set_pixel_color_bumpmap(t_int_pts vp, t_field *field, t_geom *geom)
{
	// char		*color;
	// t_color	out;
	// static int x = 0;
	// static int y = 0;
	
	
	(void)vp;
	(void)field;
	(void)geom;
	// color = geom->bumpmap.buff.buffer[(int)(y * geom->bumpmap.buff.line_bytes + x * geom->bumpmap.buff.pixel_bits / 8)];

	// y++;
	// x++;
	// if (y > geom->bumpmap.height)
	// 	y = 0;
	// if (x > geom->bumpmap.width)
	// 	x = 0;
	// out.r = get_r(color[2]);
	// out.g = get_g(color[1]);
	// out.b = get_b(color[0]);
	// // 	pixel[0] = color.b;
	// // pixel[1] = color.g;
	// // pixel[2] = color.r;
	// // pixel[3] = color.a;
	// print_color_values("COLOR", out);
	// // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// // a = ceil(round(vp.pt.pt.x) / round(geom->bumpmap.width * geom->bumpmap.height));
	// // b = ceil(round(vp.pt.pt.y) / round(geom->bumpmap.width * geom->bumpmap.height));
	// // c = ceil(round(vp.pt.pt.z) / round(geom->bumpmap.width * geom->bumpmap.height));
	// // if (((int)a + (int)b + (int)c) % 2 == 0)
	// // 	return (field->chckbd.c1);
	// // else
	// // 	return (field->chckbd.c2);
	return (add_color("255, 255, 255, 0"));
}