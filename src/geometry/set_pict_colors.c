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
	t_vec_pos vp;
	vp.v = create_vect(0, 0, 0);
	vp.pt = create_vect(LONG_MAX, LONG_MAX, LONG_MAX);
	return (vp);
}

static t_vec_pos get_min_vect(t_vec_pos cur, t_vec_pos *new, t_geom *geom)
{
	t_vec_pos out;

	out = cur;
	if (modulo_vector(cur.pt) > modulo_vector(new[0].pt))
	{
		out = new[0];
		out.c = geom->color;
	}
	if (geom->type != PLANE)
		if (modulo_vector(out.pt) > modulo_vector(new[1].pt))
		{
			out = new[1];
			out.c = geom->color;
		}
	return (out);
}

static t_vec_pos get_int_pt(t_vec_pos vps, t_geom *geom)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_vec_pos	vp_int;

	ptr = geom;
	vp_int = init_vp();
	while (ptr)
	{
		if (geom->type = SPHERE)
			out = int_vect_esfera(vps, ptr->vp.pt, ptr->r);
		else if (geom->type = CYLINDER)
			out = int_vect_cilind(vps, ptr->vp, ptr->r);
		else if (geom->type = PLANE)
			out = int_vect_plano(vps, ptr->vp);
		vp_int = get_min_vect(vps, out, geom);
		free(out);
		ptr = ptr->next;
	}
	return (vp_int);
}

void set_pict_colors(t_field field)
{
	int		i;

	i = -1;
	while (i++ < WIN_X * WIN_Y)
//	while (i++ < field.w_wide * field.w_high)
		field.camera.int_vectors[i] = get_int_pt(field.camera.field_vectors[i],field.geom);
}
/*
void fractol_draw(t_fract *frac)
{
	t_indexes ind;
	int result;
	t_img_buff buf;

	buf.buffer = mlx_get_data_addr(frac->image, &buf.pixel_bits,
								   &buf.line_bytes, &buf.endian);
	ind.i = frac->frame - 1;
	while (++ind.i < frac->size_x - frac->frame)
	{
		ind.j = frac->frame - 1;
		while (++ind.j < frac->size_y - frac->frame)
		{
			frac->z0.re = (frac->c1.re + ind.i * frac->escala_x);
			frac->z0.im = (frac->c1.im + ind.j * frac->escala_y);
			result = frac->function(frac->c, frac->z0, frac->limit);
			put_pixel_color(&buf.buffer[ind.j * buf.line_bytes +
										ind.i * buf.pixel_bits / 8],
							frac->color[result]);
		}
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image, 0, 0);
}*/
