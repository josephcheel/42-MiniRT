/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgihts_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/09 13:21:37 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_light	*ft_clone_light(t_light *light)
{
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	new_light->pos = light->pos;
	new_light->ratio = light->ratio;
	new_light->color = light->color;
	new_light->next = NULL;
	return (new_light);
}

t_light	*ft_clone_lightning(t_light *light)
{
	int		size;
	t_light	*new_light;

	size = ft_lightsize(light);
	while (size--)
	{
		new_light = ft_clone_light(light);
		ft_lightadd_back(&new_light, new_light);
		light = light->next;
	}
	return (new_light);
}
