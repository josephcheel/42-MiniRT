#include "../inc/minirt.h"

int	rgb_to_hex(t_color color)
{
	int	hex;

	hex = (color.r << 16) | (color.g << 8) | color.b;
	return (hex);
}