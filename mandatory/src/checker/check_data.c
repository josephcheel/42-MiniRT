#include "../../inc/minirt.h"

/*
Checks if a string is a double with format [NBR[.]NBR]
*/

bool	ft_isdouble(char *nbr)
{
	int	i;
	int	count_nbr;
	int	count_dot;

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

int main(void)
{
	char *str = "1-" ;//"10.00.1";
	bool result = ft_isdouble(str);
	printf("%d", result);
}

// int	ft_check_line_data(char **content)
// {
// 	if (ft_strcmp(content[0], "A") == 0)
// 		;
// 	if (ft_strcmp(content[0], "C") == 0)
// 		;
// 	if (ft_strcmp(content[0], "L") == 0)
// 		;
// 	if (ft_strcmp(content[0], "pl") == 0)
// 		;
// 	if (ft_strcmp(content[0], "sp") == 0)
// 		;
// 	if (ft_strcmp(content[0], "cy") == 0)
// 		;
// }