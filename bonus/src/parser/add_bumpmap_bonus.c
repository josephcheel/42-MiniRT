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
	if (bumpmap.width > 0 && bumpmap.height > 0)
		bumpmap.buff.buffer = mlx_get_data_addr(bumpmap.mlx.img, \
			&bumpmap.buff.pixel_bits, &bumpmap.buff.line_bytes, \
			&bumpmap.buff.endian);
	bumpmap.is_bumpmap = true;
	return (bumpmap);
}
