/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/03 20:02:33 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	prt_help(void)
{
	ft_putstr_fd("\x1b[38;5;210m=========Usage==========\x1b[0m\n", 2);
	ft_putstr_fd("./miniRT \x1b[34;01mfile_name\x1b[0m\n", 2);
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

int	main(int av, char **ac)
{
	t_field	*field;

	if (av < 2 || !check_arg(ac[1]))
		return (prt_help());
	field = init_vars(ac[1]);
	free_field(field);
	return (0);
}
