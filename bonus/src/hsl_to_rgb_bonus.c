/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/13 12:45:33 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_bonus.h"

float	hue_to_rgb(float v1, float v2, float vH)
{
	if (vH < 0)
		vH += 1;
	if (vH > 1)
		vH -= 1;
	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);
	if ((2 * vH) < 1)
		return (v2);
	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);
	return (v1);
}

void	hsl_to_rgb(t_color *c)
{
	float	v1;
	float	v2;
	float	hue;

	if (c->s == 0)
	{
		c->r = (int)(c->l * 255);
		c->g = c->r;
		c->b = c->r;
	}
	else
	{
		hue = c->h / 360;
		if (c->l < 0.5)
			v2 = (c->l * (1 + c->s));
		else
			v2 = ((c->l + c->s) - (c->l * c->s));
		v1 = 2 * c->l - v2;
		c->r = (int)(255 * hue_to_rgb(v1, v2, hue + (1.0f / 3)));
		c->g = (int)(255 * hue_to_rgb(v1, v2, hue));
		c->b = (int)(255 * hue_to_rgb(v1, v2, hue - (1.0f / 3)));
	}
}
