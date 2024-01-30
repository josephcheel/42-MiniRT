/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_clone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/27 17:52:13 by jcheel-n         ###   ########.fr       */
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
	t_light	*tmp;
	t_light	*new_light;
	t_light	*new_lst;

	new_lst = NULL;
	new_light = NULL;
	tmp = light;
	size = ft_lightsize(light);
	while (size--)
	{
		new_light = ft_clone_light(tmp);
		ft_lightadd_back(&new_lst, new_light);
		tmp = tmp->next;
	}
	return (new_lst);
}
