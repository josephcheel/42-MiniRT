/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/05 18:31:41 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	prt_help(void)
{
	ft_putstr_fd("\x1b[38;5;210m=========Usage==========\x1b[0m\n", 2);
	ft_putstr_fd("./miniRT \x1b[34;01mfilename\x1b[0m\n", 2);
	ft_putstr_fd("\x1b[38;5;210m====Parameter desctiprion=====\x1b[48;5;0m\n", 2);
	ft_putstr_fd("\x1b[34;01mfilename: \x1b[0mname of the file with extension .rt\n", 2);
	ft_putstr_fd("\033[38;5;213m\texample:\x1b[0m example.rt\n", 2);
	ft_putstr_fd("\x1b[38;5;146mSee README file for more information\n", 2);
	return (0);
}

int	check_arg(char *s)
{
	int	len_str;

	len_str = ft_strlen(s);
	s = &s[len_str - 3];
	if (!ft_strcmp(s, ".rt"))
		return (1);
	return (0);
}
/*
** Check if the file has the mandatory objects[A, L, C]
*/
int	validate_scene_file(char *filename)
{
	char	**content;
	char	*line;
	int		fd;
	int		ambient;
	int		light;
	int		camera;
	
	ambient = 0;
	light = 0;
	camera = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "File Error\n", 12));
	line = get_next_line(fd);
	while (line)
	{
		content = ft_split(line, ' ');
		if (ft_strcmp(content[0], "A") == 0)
			ambient++;
		else if (ft_strcmp(content[0], "L") == 0)
			light++;
		else if (ft_strcmp(content[0], "C") == 0)
			camera++;
		ft_array_free(content, ft_array_size(content));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	
	if (ambient < 1 || light < 1 || camera < 1)
		return (write(2, "The file does not has All Mandatory Objects\n Ambient Light(A), Light(C) and Camera(C)\n", 87));
	else	if (ambient > 1 || light > 1 || camera > 1)
		return (write(2, "Error: Duplicated Object\n", 26));
	return (0);
}

int	main(int ac, char **av)
{
	t_field	*field;

	if (ac < 2 || !check_arg(av[1]))
		return (prt_help());
	if (validate_scene_file(av[1]))
		return (1);
	field = initializer(av[1]);
	if (!field)
		return (write(2, "Error: Malloc\n", 15));

	//DEBUG
	field = init_vars(av[1]);
	if (!field)
		return(write(2, "Error: Malloc\n", 15));
	ft_print_camera(field);
	ft_print_light(field);
	ft_print_ambient(field);
	ft_print_geometry_full(field->geom);

	mlx_loop(field->mlx.mlx);
	
	free_field(field);
	return (0);
}
