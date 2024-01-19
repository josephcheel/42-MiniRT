/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/14 00:52:39 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_color_values(char *s, t_color c)
{
	printf("%s", s);
	printf("R=%x, G=%x, B=%x, a=%x, H=%f, S=%f, L=%f\n", \
	c.r, c.g, c.b, c.a, c.h, c.s, c.l);
}

static bool	is_bhd_cam(t_vec3 pint, t_vec3 pi, t_vec3 vx)
{
	t_vec3		temp;
	double		aux;

	temp = conv_v_unit(resta_vector(pint, pi));
	aux = prod_escalar(vx, temp);
	if (aux > 0)
		return (false);
	return (true);
}

static t_int_pts	get_min_vect(t_int_pts cur, t_vec_pos *new,
						t_geom *geom)
{
	t_int_pts	out;
	double		long_cur;
	int			i;

	out = cur;
	if (!new)
		return (cur);
	long_cur = modulo_vector(cur.pt.pt);
	i = -1;
	while (++i < 2)
	{
		if (modulo_vector(new[i].pt) < long_cur)
		{
			out.pt = new[i];
			out.pt.c = geom->color;
			out.geom = geom;
		}
	}
	return (out);
}

/*
	t_vec_pos	aux;
	aux = new[0];
	double		long_new;
	long_new = modulo_vector(new[0].pt);
	if (geom->type != PLANE && modulo_vector(new[1].pt) < long_new)
	{
		aux = new[1];
		long_new = modulo_vector(new[1].pt);
	}
	if (long_cur > long_new && !is_behind_cam(aux, vps))
	{
	}

*/

t_int_pts	calcula_color(int pixel, t_field *field)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_int_pts	vp_int;
	t_vec_pos	*vps;
	int			i;

	ptr = field->geom;
	vps = &field->camera.field_vp[pixel];
	vp_int.pt = init_vp(vps->c);
	vp_int.geom = NULL;
	while (ptr)
	{
		out = get_int_pt(vps, ptr);
		i = -1;
		while (++i < 2)
		{
			if (out && !is_bhd_cam(out[i].pt, vps->pt, field->camera.center.vx))
				vp_int = get_min_vect(vp_int, out, ptr);
			if (ptr->type == PLANE)
				i++;
		}
		ptr = ptr->next;
		free (out);
	}
	vp_int.pt.c = set_pixel_color(vp_int, field);
	return (vp_int);
}

void	print_pixel_values(int x, int y, t_field *field)
{
	int			k;
	t_color		c;
	t_int_pts	inters;
	t_img_buff	buf;

	if (x < FRAME || y < FRAME || x > field->mlx.size_x - FRAME || \
		y > field->mlx.size_y - FRAME)
		return ;
	buf.buffer = mlx_get_data_addr(field->mlx.img, &buf.pixel_bits,
			&buf.line_bytes, &buf.endian);
	k = y * buf.line_bytes + x * buf.pixel_bits / 8;
	c.b = buf.buffer[k];
	c.g = buf.buffer[k + 1];
	c.r = buf.buffer[k + 2];
	c.a = buf.buffer[k + 3];
	k = (x - FRAME) + (y - FRAME) * (field->mlx.size_x - 2 * FRAME);
	printf("========================Datos generales=======================\n");
	ft_print_vec3("El observador de la cámara está en: ", \
	field->camera.observer);
	printf("==============================================================\n");
	ft_print_vec3("El centro de la cámara está en: ", field->camera.center.pos);
	ft_print_vec3("El observador respecto a la cámara está en: ", \
	resta_vector(field->camera.observer, field->camera.center.pos));
	printf("Modulo vector observador cámara está en: %f\n", \
	modulo_vector(resta_vector(field->camera.observer, \
	field->camera.center.pos)));
	printf("El punto es x=%i, y=%i\n", x, y);
	ft_print_vec3("El punto de luz está en: ", field->light->pos);
	printf("Datos del vector del pixel de la cámara:\n");
	ft_print_vec3("El Vector camara es", field->camera.field_vp[k].pt);
	ft_print_vec3("El Vector direccional  es", field->camera.field_vp[k].v);
	print_color_values("El Color del objeto es: ", field->camera.field_vp[k].c);
	printf("Datos del punto visualizado por la cámara:\n");
	ft_print_vec3("El Vector camara es", field->camera.int_vp[k].pt.pt);
	ft_print_vec3("El Vector direccional  es ", field->camera.int_vp[k].pt.v);
	print_color_values("El color resultante es: ", \
	field->camera.int_vp[k].pt.c);
	print_color_values("El color de la pantallea es: ", c);
	inters = calcula_color(k, field);
	printf("Datos del punto calculado:\n");
	ft_print_vec3("El Vector int es", inters.pt.pt);
	ft_print_vec3("El Vector direccion int  es ", inters.pt.v);
	print_color_values("El color resultante es: ", inters.pt.c);
	printf("==============================================================\n");
}
