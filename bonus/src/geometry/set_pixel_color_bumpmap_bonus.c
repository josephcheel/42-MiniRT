/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_bumpmap_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:06:02 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/27 16:06:11 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"



void	set_pixel_color_bumpmap(t_int_pts *vp_int, t_field *field)
{
	(void)vp;
	(void)field;
	/*
	if (vp->geom->type == PLANE)
		{

		}
		i_indexes p;

		// x = 0;
		// y = 0;

		if (vp->geom->type == PLANE)
		{
			if (vp->pt.pt.x  > geom->bumpmap.width - 1)
				tmpx = (int)vp->pt.pt.x %  geom->bumpmap.width;
			else
				tmpx = (vp->pt.pt.x);

			if (vp->pt.pt.x  < 0)
				tmpx = geom->bumpmap.width - 1- vp->pt.pt.x;
			else
				tmpx = (vp->pt.pt.x);

			if (vp->pt.pt.y > geom->bumpmap.height - 1)
				tmpy = (int)vp->pt.pt.y % geom->bumpmap.height;
			else
				tmpy = (vp->pt.pt.y);

			if (vp->pt.pt.y  < 0 )
				tmpy = (geom->bumpmap.height -1 - vp->pt.pt.y);
			else
				tmpy = (vp->pt.pt.y);
			// if (fabs(vp->pt.pt.x) > geom->bumpmap.width - 1)
			// 	y = (int)vp->pt.pt.x % geom->bumpmap.width;
			// if (fabs(vp->pt.pt.y) > geom->bumpmap.height - 1)
			// 	x = abs((int)vp->pt.pt.y % geom->bumpmap.height);
			// printf("IMAGE WIDTH : %d HEAIGHT %d\n", geom->bumpmap.width, geom->bumpmap.height);
			// printf("AFT X %d Y %d\n", x, y);
			// printf("LIGHT ADJUSTMENT %f\n", geom->bumpmap.h_map[x + y * (geom->bumpmap.width)]);
			//printf("%d\n", x + (y * geom->bumpmap.width));
			x = tmpx;
			y = tmpy;
			if (x + (y * geom->bumpmap.width ) >= 0 && x + (y * geom->bumpmap.width ) < (geom->bumpmap.height * geom->bumpmap.width))
			{
				vp->pt.v = geom->bumpmap.normal_map[x + (y * geom->bumpmap.width )].v;
				// vp->pt.pt.z += (geom->bumpmap.normal_map[x + (y * geom->bumpmap.width )].h);
				vp->pt.c = add_color("0,0,255");
			}
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
		// return (vp.geom->color);
	*/
}