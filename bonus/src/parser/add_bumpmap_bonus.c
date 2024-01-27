/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bumpmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:28:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/27 17:46:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static double	get_lum_map(char *buff)
{
	t_color	c;

	c.b = buff[0];
	c.g = buff[1];
	c.r = buff[2];
	c.a = buff[3];
	rgb_to_hsl(&c);
	return (c.l);
}

static t_vec3	get_slope(int pos, t_bumpmap *bump)
{
	t_vec3	out;
	t_vec3	ang;
	int		k[3];

	ang.x = 0;
	k[3] = bump->width * bump->height;
	k[0] = (pos - 1 + k[3]) % k[3];
	k[1] = (pos + 1 + k[3]) % k[3];
	ang.y = acos((get_lum_map(&bump->buff.buffer[k[1]]) - \
				get_lum_map(&bump->buff.buffer[k[0]])) / BM_PIXEL);
	k[0] = (pos - bump->buff.line_bytes + k[3]) % k[3];
	k[1] = (pos + bump->buff.line_bytes + k[3]) % k[3];
	ang.z = acos(get_lum_map(&bump->buff.buffer[k[1]]) - \
				get_lum_map(&bump->buff.buffer[k[0]]) / BM_PIXEL);
	out = martix_rot(create_vect(0, 0, 1), ang);
	return (out);
}

static bool	create_bump_matrix(t_bumpmap *bumpmap)
{
	t_indexes	p;
	int			k;

	p.i = -1;
	p.j = 0;
	bumpmap->normal_map = malloc(sizeof(t_matrix) * \
				(bumpmap->height * bumpmap->width));
	if (!bumpmap->normal_map)
		return (false);
	while (++p.i < bumpmap->width && p.j < bumpmap->height)
	{
		k = p.j * bumpmap->buff.line_bytes + p.i * bumpmap->buff.pixel_bits / 8;
		bumpmap->normal_map[p.i * p.j] = get_slope(k, bumpmap);
		if (p.i == bumpmap->width)
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
