/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:48:39 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/02 02:26:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

static double	get_digits(const char *str)
{
	double	decimal;
	double	result;
	int		isdecimal;

	isdecimal = 0;
	decimal = 1.0;
	result = 0.0;
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str == '.')
		{
			str++;
			isdecimal = 1;
		}
		if (isdecimal)
		{
			decimal *= 0.1;
			result = result + (*str - '0') * decimal;
		}
		else
			result = (result * 10) + (*str - 48);
		str++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;

	sign = 1;
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ' )
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = get_digits(str);
	return (result * sign);
}

// int main()
// {
// 	char *str = "123.3239203902";
// 	printf("%f\n", ft_atof(str));
// 	return (0);
// }
