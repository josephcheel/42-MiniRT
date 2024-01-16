/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_lstcreate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 11:12:54 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_light	*ft_lightlast(t_light *lst)
{
	t_light	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lightadd_back(t_light **lst, t_light *new_node)
{
	t_light	*ret;

	if (*lst)
	{
		ret = ft_lightlast(*lst);
		ret->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*lst = new_node;
		(*lst)->next = NULL;
	}
}

int	ft_lightsize(t_light *lst)
{
	int		i;
	t_light	*tmp;

	i = 0;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (i);
		i++;
	}
	return (i);
}

void	ft_free_light(t_light **head)
{
	t_light	*temp;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
}
