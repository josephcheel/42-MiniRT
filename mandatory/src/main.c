/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/20 22:44:57 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	prt_help(void)
{
	ft_putstr_fd(CHR_RED, 2);
	ft_putstr_fd("=========Usage==========\n", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("./miniRT ", 2);
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

int	check_extension(char *s)
{
	int	len_str;

	len_str = ft_strlen(s);
	s = &s[len_str - 3];
	if (!ft_strcmp(s, ".rt"))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_field	*field;

	if (ac != 2 || !check_extension(av[1]))
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
