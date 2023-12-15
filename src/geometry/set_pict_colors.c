/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pict_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static t_vec_pos	init_vp(void)
{
	t_vec_pos	vp;

	vp.v = create_vect(0, 0, 0);
	vp.pt = create_vect(LONG_MAX, LONG_MAX, LONG_MAX);
	return (vp);
}

void	put_pixel_color(char *pixel, t_color color)
{
	pixel[0] = color.r;
	pixel[1] = color.g;
	pixel[2] = color.b;
	pixel[3] = color.a;
}

static t_vec_pos	get_min_vect(t_vec_pos cur, t_vec_pos *new, t_geom *geom)
{
	t_vec_pos		out;
	unsigned int	long_cur;
	unsigned int	long_new;

	out = cur;
	long_cur = modulo_vector(cur.pt);
	long_new = modulo_vector(new[0].pt);
	if (long_cur > long_new)
	{
		out = new[0];
		out.c = geom->color;
	}
	if (geom->type != PLANE)
	{
		long_cur = modulo_vector(out.pt);
		long_new = modulo_vector(new[1].pt);
		if (long_cur > long_new)
		{
			out = new[1];
			out.c = geom->color;
		}
	}
	return (out);
}

static t_vec_pos	get_int_pt(t_vec_pos vps, t_geom *geom)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_vec_pos	vp_int;

	ptr = geom;
	vp_int = init_vp();
	while (ptr)
	{
		if (geom->type == SPHERE)
			out = int_vect_esfera(vps, ptr->vp.pt, ptr->r);
		else if (geom->type == CYLINDER)
			out = int_vect_cilind(vps, ptr->vp, ptr->r);
		else if (geom->type == PLANE)
			out = int_vect_plano(vps, ptr->vp);
		vp_int = get_min_vect(vps, out, geom);
		free(out);
		ptr = ptr->next;
	}
	return (vp_int);
}

void	set_pict_colors(t_field field)
{
	t_indexes	ind;
	t_img_buff	buf;

	buf.buffer = mlx_get_data_addr(field.mlx.img, &buf.pixel_bits,
			&buf.line_bytes, &buf.endian);
	ind.i = field.mlx.frame - 1;
	while (++ind.i < field.mlx.size_x - field.mlx.frame)
	{
		ind.j = field.mlx.frame - 1;
		while (++ind.j < field.mlx.size_y - field.mlx.frame)
		{
			ind.k = ind.i + ind.j * field.mlx.size_y;
			field.camera.int_vectors[ind.k] = \
				get_int_pt(field.camera.field_vectors[ind.k], field.geom);
			put_pixel_color(&buf.buffer[ind.j * buf.line_bytes + \
				ind.i * buf.pixel_bits / 8], field.camera.int_vectors[ind.k].c);
		}
	}
	mlx_put_image_to_window(field.mlx.mlx, field.mlx.win, field.mlx.img, 0, 0);
}
