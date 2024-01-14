/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hsl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:25:20 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/03 16:25:27 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_bonus.h"

double	fc_min(t_color *c)
{
	double	min_val;

	min_val = fmin((double) c->r / 255.0, (double) c->g / 255.0);
	min_val = fmin(min_val, (double) c->b / 255.0);
	return (min_val);
}

double	fc_max(t_color *c)
{
	double	max_val;

	max_val = fmax((double) c->r / 255.0, (double) c->g / 255.0);
	max_val = fmax(max_val, (double) c->b / 255.0);
	return (max_val);
}

void	rgb_to_hsl(t_color *c )
{
	double	f_c_min;
	double	f_c_max;

	f_c_min = fc_min(c);
	f_c_max = fc_max(c);
	c->l = (f_c_min + f_c_max) / 2;
	if (f_c_min == f_c_max)
	{
		c->s = 0;
		c->h = 0;
		return ;
	}
	else if (c->l < 0.5)
		c->s = (f_c_max - f_c_min) / (f_c_max + f_c_min);
	else
		c->s = (f_c_max - f_c_min) / (2.0 - f_c_max - f_c_min);
	if (f_c_max == c->r / 255.0)
		c->h = 60 * (c->g - c->b) / 255.0 / (f_c_max - f_c_min);
	if (f_c_max == c->g / 255.0)
		c->h = 60 * (c->b - c->r) / 255.0 / (f_c_max - f_c_min) + 120;
	if (f_c_max == c->b / 255.0)
		c->h = 60 * (c->r - c->g) / 255.0 / (f_c_max - f_c_min) + 240;
	if (c->h < 0)
		c->h = c->h + 360;
}
