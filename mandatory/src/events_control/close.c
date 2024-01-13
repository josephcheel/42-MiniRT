/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/13 11:56:39 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/// @brief Function to free all variables and close the windows.
/// @param field 
/// @return integer as a return function.
int	ft_close(t_field *field)
{
	printf("Closing program...\n");
	free_field(field);
	exit(EXIT_SUCCESS);
}

/*
int	ft_close(int keycode, t_mlx *mlx)
{
	if (keycode == XK_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}
*/