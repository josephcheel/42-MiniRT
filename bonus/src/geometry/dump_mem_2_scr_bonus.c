/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem_2_scr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static t_indexes	inc_indexes(t_indexes ind, t_indexes lim)
{
	t_indexes	in;

	in.i = ind.i;
	in.j = ind.j;
	if (in.i == lim.i - 1)
	{
		in.i = -1;
		in.j++;
	}
	return (in);
}

static t_indexes	alloc_field_mem(t_field *field)
{
	t_indexes	lim;

	lim.i = field->mlx.size_x - FRAME * 2;
	lim.j = field->mlx.size_y - FRAME * 2;
	field->camera.field_vp = \
		(t_vec_pos *) malloc(((lim.i) * (lim.j)) * sizeof(t_vec_pos));
	field->camera.int_vp = \
		(t_int_pts *)malloc(((lim.i) * (lim.j)) * sizeof(t_int_pts));
	if (!field->camera.field_vp || !field->camera.int_vp)
	{
		lim.i = 0;
		lim.j = 0;
	}
	return (lim);
}

static void	put_pixel_color(char *pixel, t_color color)
{
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
	pixel[3] = color.a;
}

int	dump_mem_2_scr(t_field *field)
{
	t_indexes	in;
	t_img_buff	buf;
	t_indexes	lim;

	buf.buffer = mlx_get_data_addr(field->mlx.img, &buf.pixel_bits,
			&buf.line_bytes, &buf.endian);
	in.i = -1;
	in.j = 0;
	lim = alloc_field_mem(field);
	if (lim.i == 0 && lim.j == 0)
		return (1);
	while (++in.i < lim.i && in.j < lim.j)
	{
		in.k = in.i + in.j * (lim.i);
		def_pixel_vp(field, in, lim);
		get_colored_int_pt(in.k, field);
		put_pixel_color(&buf.buffer[(in.j + FRAME) * buf.line_bytes + \
			(in.i + FRAME) * buf.pixel_bits / 8], \
			field->camera.int_vp[in.k].pt.c);
		in = inc_indexes(in, lim);
	}
	mlx_put_image_to_window(field->mlx.mlx, field->mlx.win, \
		field->mlx.img, 0, 0);
	return (0);
}

int	move_light(t_field *field)
{
	t_indexes	in;
	t_img_buff	buf;
	t_indexes	lim;

	buf.buffer = mlx_get_data_addr(field->mlx.img, &buf.pixel_bits, \
					&buf.line_bytes, &buf.endian);
	in.i = -1;
	in.j = 0;
	lim = alloc_field_mem(field);
	if (lim.i == 0 && lim.j == 0)
		return (1);
	while (++in.i < lim.i && in.j < lim.j)
	{
		in.k = in.i + in.j * (lim.i);
		get_colored_int_pt(in.k, field);
		put_pixel_color(&buf.buffer[(in.j + FRAME) * buf.line_bytes + \
			(in.i + FRAME) * buf.pixel_bits / 8], \
			field->camera.int_vp[in.k].pt.c);
		in = inc_indexes(in, lim);
	}
	mlx_put_image_to_window(field->mlx.mlx, field->mlx.win, \
		field->mlx.img, 0, 0);
	return (0);
}
