/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 00:07:36 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Check for the nbr of words in each line. Return 1 if okey and 0 if not
*/
int	check_content(char **type)
{
	int		size;

	size = ft_array_size(type);
	if ((ft_strcmp(type[0], "A") == 0) && size != 3 )
		return (0);
	else if ((ft_strcmp(type[0], "C") == 0|| ft_strcmp(type[0], "L") == 0|| ft_strcmp(type[0], "sp") == 0 || ft_strcmp(type[0], "pl") == 0) && size != 4)
		return (0);
	else if ((ft_strcmp(type[0], "cy")) == 0 && size != 6)
		return (0);
	return (1);
}

int	is_geo(char *line)
{
	int		i;
	char	**element;
	char	**geos;

	i = 0;
	
	geos = ft_split(GEO_IDENT, ' ');
	element = ft_split(line, ' ');
	if (!check_content(element))
		i = MAX_GEOM;
	while (i < MAX_GEOM)
	{
		if (!ft_strcmp(element[0], geos[i]))
		{
			ft_array_free(geos, ft_array_size(geos));
			ft_array_free(element, ft_array_size(element));
			return (i);
		}
		i++;
	}
	ft_array_free(geos, ft_array_size(geos));
	ft_array_free(element, ft_array_size(element));
	return (-1);
}

int	is_device(char *line)
{
	int		i;
	char	**element;
	char	**devices;

	i = 0;
	devices = ft_split(DEV_IDENT, ' ');
	element = ft_split(line, ' ');
	if (!check_content(element))
		i = MAX_GEOM;
	while (i < MAX_DEVICES)
	{
		if (!ft_strcmp(element[0], devices[i]))
		{
			ft_array_free(devices, ft_array_size(devices));
			ft_array_free(element, ft_array_size(element));
			return (i);
		}
		i++;
	}
	ft_array_free(devices, ft_array_size(devices));
	ft_array_free(element, ft_array_size(element));
	return (-1);
}

t_field	*init_vars(char *filename)
{
	t_field	*field;
	char	*raw_line;
	char	*line;
	int		fd;

	field = (t_field *)malloc(sizeof(t_field));
	if (!field)
		return (NULL);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File Error\n", 2);
		return (field);
	}
	raw_line = get_next_line(fd);
	while (raw_line)
	{
		line = ft_strtrim(raw_line, "\n");
		if (!line || ft_strlen(line) == 0)
			;
		else if (is_device(line) != -1)
		{
			printf("es un device -- $%s$\n", line);
			get_devices(field, line);
		}
		else if (is_geo(line) != -1)
		{
			printf ("es un a geometria -- $%s$\n", line);
			//get_geom(field, line);
		}
		else
			ft_putstr_fd("Wrong Line Settings\n", 2);
		free(line);
		free (raw_line);
		raw_line = get_next_line(fd);
	}
	free(raw_line);
	return (field);
}

void	free_field(t_field *field)
{
	free(field);
	return ;
}
