/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bumpmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:28:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 16:02:40 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	create_bump_matrix(t_bumpmap *bumpmap)
{
	t_vec2	p;
	t_color	c;
	int		k;

	p.x = -1;
	p.y = 0;
	bumpmap->z_map = malloc(sizeof(float *) * (bumpmap->height * bumpmap->width));
	if (bumpmap->z_map)
	while (++p.x < bumpmap->width && p.y < bumpmap->height)
	{
		k = p.y * bumpmap->buff.line_bytes + p.x * bumpmap->buff.pixel_bits / 8;
		c.b = bumpmap->buff.buffer[k];
		c.g = bumpmap->buff.buffer[k + 1];
		c.r = bumpmap->buff.buffer[k + 2];
		c.a = bumpmap->buff.buffer[k + 3];
		rgb_to_hsl(&c);
		k = p.x + p.y * bumpmap->width;
		bumpmap->z_map[k] = c.l * 10000000;
		if (p.x == bumpmap->width - 1)
		{
			p.x = -1;
			p.y++;
		}
	}
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
	bumpmap.is_bumpmap = true;
	if (bumpmap.width <= 0 && bumpmap.height <= 0)
		return (bumpmap);
	bumpmap.buff.buffer = mlx_get_data_addr(bumpmap.mlx.img, \
		&bumpmap.buff.pixel_bits, &bumpmap.buff.line_bytes, \
		&bumpmap.buff.endian);
	create_bump_matrix(&bumpmap);
	return (bumpmap);
}
