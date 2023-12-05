#include "../inc/minirt.h"

int	ft_close_red_cross(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}

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