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
	(void)vp;
	(void)field;
	(void)geom;
	// t_vec3	tmp;
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (vp.geom->type == PLANE)
	{
		x = fabs(vp.pt.pt.x);
		y = fabs(vp.pt.pt.y);
		// tmp = resta_vector(vp.geom->vp.pt , vp.pt.pt);
		if (fabs(vp.pt.pt.x) > geom->bumpmap.width - 1)
			y = abs((int)vp.pt.pt.x % geom->bumpmap.width);
		if (fabs(vp.pt.pt.y) > geom->bumpmap.height - 1)
			x = abs((int)vp.pt.pt.y % geom->bumpmap.height);
		
		printf("IMAGE WIDTH : %d HEAIGHT %d\n", geom->bumpmap.width, geom->bumpmap.height);
		printf("X %d Y %d\n", x, y);
		printf("LIGHT ADJUSTMENT %f\n", geom->bumpmap.z_map[x + y * (geom->bumpmap.width)]);
		//printf("%d\n", x + (y * geom->bumpmap.width));
		if (geom->bumpmap.z_map[x + (y * geom->bumpmap.width )] > 0.0)
			vp.pt.v = prod_cte_vector(geom->bumpmap.z_map[x + (y * geom->bumpmap.width )], vp.pt.v);
		vp.pt.pt = suma_vector(vp.pt.pt, vp.pt.v);
	}
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
	return (vp.geom->color);
}