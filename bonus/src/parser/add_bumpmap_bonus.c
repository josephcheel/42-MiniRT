/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bumpmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:28:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/29 16:09:20 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static t_color	get_lum_map(char *buff)
{
	t_color	c;

	c.b = buff[0];
	c.g = buff[1];
	c.r = buff[2];
	c.a = buff[3];
	rgb_to_hsl(&c);
	c.l = (c.l + 2);
	return (c);
}

static t_vec_pos	get_slope(int pos, t_bumpmap *bump)
{
	t_vec_pos	out;
	t_vec3		ang;
	int			k[3];

	out = init_vp(get_lum_map(&bump->buff.buffer[pos]));
	ang.z = 0;
	k[2] = bump->buff.pixel_bits * bump->buff.line_bytes * 8;
	k[0] = (pos - bump->buff.pixel_bits + k[2]) % k[2];
	k[1] = (pos + bump->buff.pixel_bits + k[2]) % k[2];
	ang.y = asin((get_lum_map(&bump->buff.buffer[k[1]]).l - \
				get_lum_map(&bump->buff.buffer[k[0]]).l) / BM_PIXEL);
	k[0] = (pos - bump->buff.line_bytes * 8 + k[2]) % k[2];
	k[1] = (pos + bump->buff.line_bytes * 8 + k[2]) % k[2];
	ang.x = asin((get_lum_map(&bump->buff.buffer[k[1]]).l - \
				get_lum_map(&bump->buff.buffer[k[0]]).l) / BM_PIXEL);
	out.v = martix_rot(create_vect(0, 0, 1), ang);
	return (out);
}

static bool	create_bump_matrix(t_bumpmap *bumpmap)
{
	t_indexes	p;
	int			k;

	p.i = -1;
	p.j = 0;
	bumpmap->normal_map = malloc(sizeof(t_vec_pos) * \
				(bumpmap->height * bumpmap->width));
	if (!bumpmap->normal_map)
		return (false);
	while (++p.i < bumpmap->width && p.j < bumpmap->height)
	{
		k = p.j * bumpmap->buff.line_bytes + p.i * \
								bumpmap->buff.pixel_bits / 8;
		bumpmap->normal_map[p.i + p.j * bumpmap->width] = get_slope(k, bumpmap);
		if (p.i == bumpmap->width - 1)
		{
			p.i = -1;
			p.j++;
		}
	}
	return (true);
}

t_bumpmap	get_bumpmap(char *filename, t_field *field)
{
	t_bumpmap	bumpmap;
	int			fd;

	bumpmap.is_bumpmap = false;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Bumpmap: File Error\n", 21);
		return (bumpmap);
	}
	close(fd);
	bumpmap.mlx.img = mlx_xpm_file_to_image(field->mlx.mlx, filename, \
		&bumpmap.width, &bumpmap.height);
	if (bumpmap.width <= 0 && bumpmap.height <= 0)
		return (bumpmap);
	bumpmap.buff.buffer = mlx_get_data_addr(bumpmap.mlx.img, \
		&bumpmap.buff.pixel_bits, &bumpmap.buff.line_bytes, \
		&bumpmap.buff.endian);
	bumpmap.is_bumpmap = create_bump_matrix(&bumpmap);
	return (bumpmap);
}
