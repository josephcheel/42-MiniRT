/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/02 12:23:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	prt_help(void)
{
	printf("=========Usage==========\n");
	printf("./miniRT file_name\n");
	printf("====Parameter desctiprion=====\n");
	printf("filename: name of the file with extension .rt\n");
	printf("\texample: example.rt\n");
	printf("See README file for more information\n");
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
