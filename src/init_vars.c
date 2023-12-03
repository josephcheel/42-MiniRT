/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/02 12:23:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	is_geo(char *str)
{
	int		i;
	char	**geos;

	i = 0;
	geos = ft_split(GEO_IDENT, ' ');
	while (i < MAX_GEOM)
	{
		if (!ft_strncmp(str, geos[i], 2))
		{
			ft_array_free(geos, ft_array_size(geos));
			return (i);
		}
		i++;
	}
	ft_array_free(geos, ft_array_size(geos));
	return (-1);
}

t_field	*init_vars(char *ac)
{
	t_field	*field;
	char	*data;
	int		fd;

	field = (t_field *) malloc(sizeof(t_field));
	if (!field)
		return (NULL);
	fd = open(ac, O_RDONLY);
	data = get_next_line(fd);
	while (data)
	{
		if (data[0] == CAMERA || data[0] == LIGHT || data[0] == AMBNT_LGHT)
			printf("es un device -- %s", data);
			//get_devices(field,data);
		else if (is_geo(data) != -1)
			printf ("es un a geometria -- %s", data);
			//get_geom(field, data);
		free (data);
		data = get_next_line(fd);
	}
	free(data);
	return (field);
}

void	free_field(t_field *field)
{
	free(field);
	return ;
}
