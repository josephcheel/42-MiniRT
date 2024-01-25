/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bumpmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:28:27 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/25 00:52:47 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	create_bump_matrix(t_bumpmap *bumpmap)
{
	t_vec3	p;
	t_color	c;
	int		k;

	p.x = -1;
	p.y = 0;
	bumpmap->normal_map = malloc(sizeof(t_normal_map) * (bumpmap->height * bumpmap->width));
	if (!bumpmap->normal_map)
		return ;
	while (++p.x < bumpmap->width && p.y < bumpmap->height)
	{
		k = p.y * bumpmap->buff.line_bytes + p.x * bumpmap->buff.pixel_bits / 8;
		c.b = bumpmap->buff.buffer[k];
		c.g = bumpmap->buff.buffer[k + 1];
		c.r = bumpmap->buff.buffer[k + 2];
		c.a = bumpmap->buff.buffer[k + 3];
		rgb_to_hsl(&c);
		k = p.x + p.y * bumpmap->width;
		bumpmap->normal_map[k].h = c.l;
		if (p.x == bumpmap->width)
		{
			p.x = -1;
			p.y++;
		}
	}
	
	int		a[4];
	float 	tmp;
	p.x = -1;
	p.y = 0;
	while (++p.x < bumpmap->width && p.y < bumpmap->height)
	{
		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
		k = p.y * bumpmap->buff.line_bytes + p.x * bumpmap->buff.pixel_bits / 8;
		
		if (p.x + 1  > bumpmap->width - 1)
			tmp = (int)(p.x + 1) % bumpmap->width;
		else
			tmp = (p.x + 1);
		a[0] = tmp + p.y * bumpmap->width;
		
		tmp = 0;
		if (p.x - 1  < 0)
			tmp = bumpmap->width - 1 - p.x - 1;
		else
			tmp = (p.x - 1);
		a[1] = tmp + p.y * bumpmap->width;;
		
		tmp = 0;
		if (p.y + 1  > bumpmap->height - 1)
			tmp = (int)(p.y + 1) % bumpmap->height;
		else
			tmp = (p.y + 1);
		a[2] = p.x + tmp * bumpmap->width;
		
		tmp = 0;
		if (p.y - 1  < 0 )
			tmp = bumpmap->height - 1 - p.y - 1;
		else
			tmp = (p.y - 1);
		a[3] = p.x + tmp * bumpmap->width;

		t_vec3 ux[2];
		t_vec3 uy[2];
		t_vec3 tmp[4];
		t_vec3 normal[2];

		ux[0] = create_vect(p.x+1, 0, bumpmap->normal_map[a[0]].h);
		ux[1] = create_vect(p.x-1, 0, bumpmap->normal_map[a[1]].h);
		uy[0] = create_vect(0 , p.y+1, bumpmap->normal_map[a[2]].h);
		uy[1] = create_vect(0 , p.y-1, bumpmap->normal_map[a[3]].h);
		
		tmp[0] = resta_vector(ux[0], p);
		tmp[1] = resta_vector(ux[1], p);
		tmp[2] = resta_vector(uy[0], p);
		tmp[3] = resta_vector(uy[1], p);
		
		normal[0]  = suma_vector(tmp[0], tmp[1]);
		normal[1] = suma_vector(tmp[2], tmp[3]);
		bumpmap->normal_map[(int)p.x + ((int)p.y * bumpmap->width)].v = prod_vectorial(normal[0], normal[1]);
		if (p.x == bumpmap->width)
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
