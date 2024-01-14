/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_lstcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/12/04 04:13:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

// t_geom	*ftgeom_new(char *id, char *value)
// {
// 	t_geom	*str;

// 	str = malloc(sizeof(t_geom));
// 	if (!str)
// 		return (NULL);
// 	str->id = ft_strdup(id);
// 	str->value = ft_strdup(value);
// 	str->next = NULL;
// 	return (str);
// }

void	ft_geomadd_back(t_geom **lst, t_geom *new_node)
{
	t_geom	*ret;

	if (*lst)
	{
		ret = ft_geomlast(*lst);
		ret->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*lst = new_node;
		(*lst)->next = NULL;
	}
}

t_geom	*ft_geomlast(t_geom *lst)
{
	t_geom	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_free_geometry(t_geom **head)
{
	t_geom	*temp;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
}
