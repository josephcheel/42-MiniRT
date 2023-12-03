/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:09:05 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/03 22:09:09 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_print_array(char **array)
{
	int	i;
	int	size;

	i = 0;
	size = ft_array_size(array);
	ft_putstr_fd("\x1b[38;5;210m=====Print Array Function=====\x1b[0m\n", 1);
	while (i < size)
	{
		ft_putstr("Line ");
		ft_putnbr_fd(i, 1);
		ft_putstr(" :");
		ft_putendl_fd(array[i], 1);
		i++;
	}
}
