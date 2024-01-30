/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:53:00 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/29 18:53:01 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color	mix_color(t_color a, t_color b)
{
	t_color	c;

	c.a = (a.a + b.a);
	c.r = (a.r + b.r);
	c.g = (a.g + b.g);
	c.b = (a.b + b.b);
	rgb_to_hsl(&c);
	return (c);
}

t_color	limit_color(t_color a)
{
	t_color	c;

	c.a = fmin(a.a, 255);
	c.r = fmin(a.r, 255);
	c.g = fmin(a.g, 255);
	c.b = fmin(a.b, 255);
	rgb_to_hsl(&c);
	return (c);
}

t_color	prod_color(t_color a, t_color b)
{
	t_color	c;

	c.r = (a.r * b.r) / 255;
	c.g = (a.g * b.g) / 255;
	c.b = (a.b * b.b) / 255;
	c.a = (a.a * b.a) / 255;
	rgb_to_hsl(&c);
	return (c);
}

t_color	mult_color(t_color a, double b)
{
	t_color	c;

	c.a = a.a;
	c.h = a.h;
	c.s = a.s;
	c.l = a.l * b;
	hsl_to_rgb(&c);
	return (c);
}

t_color	init_color(void)
{
	t_color	c;

	c.r = 0;
	c.g = 0;
	c.b = 0;
	rgb_to_hsl(&c);
	return (c);
}
