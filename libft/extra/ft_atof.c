#include "../inc/libft.h"
#include <stdio.h>

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int 		isdecimal;
	double		decimal;

	isdecimal = 0;
	decimal = 1.0;
	result = 0.0;
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
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str == '.')
		{
			isdecimal = 1;
			str++;
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
	return (result * sign);
}

// int main()
// {
// 	char *str = "123.3239203902";
// 	printf("%f\n", ft_atof(str));
// 	return (0);
// }