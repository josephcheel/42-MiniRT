/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:53:28 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/16 02:39:44 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

/*
Checks if a string is a double with format [NBR[.]NBR]
*/

bool	ft_isdouble(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-' && ft_strlen(nbr) > 1)
		i++;
	while (!nbr[i] || ft_isdigit(nbr[i]))
	{
		if (!nbr[i])
			return (true);
		i++;
	}
	if (nbr[i] == '.')
		i++;
	while (!nbr[i] || ft_isdigit(nbr[i]))
	{
		if (!nbr[i])
			return (true);
		i++;
	}
	if (!ft_isdigit(nbr[i]))
		return (false);
	return (true);
}

static int	is_vect3_loop(char *str, int i)
{
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '.'))
		i++;
	if (str[i] == ',')
		i++;
	else
		return (-1);
	if (!str[i] || str[i] == ',')
		return (-1);
	return (i);
}

bool	ft_is_vec3(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ',' || str[ft_strlen(str) - 1] == ',')
		return (false);
	i = is_vect3_loop(str, i);
	if (i == -1)
		return (false);
	i = is_vect3_loop(str, i);
	if (i == -1)
		return (false);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '.'))
		i++;
	if (str[i])
		return (false);
	return (true);
}

static int	is_rgb_loop(char *str, int i)
{
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == ',')
		i++;
	else
		return (-1);
	if (!str[i] || str[i] == ',')
		return (-1);
	return (i);
}

bool	ft_is_rgb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ',' || str[ft_strlen(str) - 1] == ',')
		return (false);
	i = is_rgb_loop(str, i);
	if (i == -1)
		return (false);
	i = is_rgb_loop(str, i);
	if (i == -1)
		return (false);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (false);
	return (true);
}

// int main()
// {
// 	char *str = "255,255,25";
// 	printf("%d\n", ft_is_rgb(str));
// 	return (0);
// }	
