/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/02 01:59:16 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	prt_help(void)
{
	ft_putstr_fd(CHR_RED, 2);
	ft_putstr_fd("=========Usage==========\n", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("./miniRT \n", 2);
	ft_putstr_fd(CHR_BLUE, 2);
	ft_putstr_fd("filename\n", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(CHR_RED, 2);
	ft_putstr_fd("====Parameter desctiprion=====\n", 2);
	ft_putstr_fd(CHR_BLUE, 2);
	ft_putstr_fd("filename: ", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("name of the file with extension .rt\n", 2);
	ft_putstr_fd(CHR_MGENTA, 2);
	ft_putstr_fd("\t example: ", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("example.rt\n", 2);
	ft_putstr_fd(CHR_README, 2);
	ft_putstr_fd("See README file for more information\n", 2);
	ft_putstr_fd(RESET, 2);
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
** Print the mandatory objects[A, L, C] message.
*/
int	prt_error(void)
{
	int	out;

	out = write(2, "The file does not has All Mandatory Objects\n", 44);
	out += write(2, "Ambient Light(A), Light(L) and Camera(C)\n", 42);
	return (out);
}

/*
** Check if the file has the mandatory objects[A, L, C]
*/
int	validate_scene_file(char *filename)
{
	char	**content;
	char	*line;
	int		fd;
	t_vec3	elem;

	elem.x = 0;
	elem.y = 0;
	elem.z = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "File Error\n", 12));
	line = get_next_line(fd);
	while (line)
	{
		content = ft_split(line, ' ');
		if (ft_strcmp(content[0], "A") == 0)
			elem.x ++;
		else if (ft_strcmp(content[0], "L") == 0)
			elem.y++;
		else if (ft_strcmp(content[0], "C") == 0)
			elem.z++;
		ft_array_free(content, ft_array_size(content));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (elem.x < 1 || elem.y < 1 || elem.z < 1)
		return (prt_error());
	else if (elem.x > 1 || elem.y > 1 || elem.z > 1)
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
	if (dump_mem_2_scr(field))
		return (write(2, "Error: Malloc\n", 15));
	mlx_loop(field->mlx.mlx);
	free_field(field);
	return (0);
}
