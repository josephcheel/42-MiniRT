/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:00:25 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/20 22:04:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
@brief Check if a string is in a string array.
@return 1 if str is in array, 0 otherwise.
*/
bool	ft_isstrarray(char *str, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strcmp(str, array[i]))
			return (1);
		i++;
	}
	return (0);
}
