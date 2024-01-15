/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:25:20 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/03 16:25:27 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_bonus.h"

int	rgb_to_hex(t_color color)
{
	int	hex;

	hex = (color.r << 16) | (color.g << 8) | color.b;
	return (hex);
}