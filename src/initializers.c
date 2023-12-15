#include "../inc/minirt.h"

void init_mlx(t_field *field)
{
	field->mlx.mlx = mlx_init();
	field->mlx.win = mlx_new_window(field->mlx.mlx, WIN_X, WIN_Y, WIN_NAME);
	field->mlx.img = mlx_new_image(field->mlx.win, WIN_X, WIN_Y);
	field->mlx.frame = FRAME;
	field->mlx.size_x = WIN_X;
	field->mlx.size_y = WIN_Y;
	mlx_hook(field->mlx.win, 17, 0, ft_close_red_cross, &field->mlx);
	mlx_key_hook(field->mlx.win, ft_close, &field->mlx);
	// mlx_loop(field->mlx.mlx);
}

t_field	*init_field(void)
{
	t_field *field;

	field = (t_field *)malloc(sizeof(t_field));
	if (!field)
	{
		write(2, "Error: Malloc\n", 15);
		return (NULL);
	}
	field->geom = NULL;
	field->light = NULL;
	return (field);
}

t_field *initializer(char *av)
{
	t_field *field;

	field = init_field();
	if (!field)
		return (NULL);
	init_mlx(field);
	if (read_file(av, field))
		return (NULL);
	return (field);
}
