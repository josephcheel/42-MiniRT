/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:16:35 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/10/20 13:26:50 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	wordcounter(char const *s)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ( ft_isspace(s[i]))
			i++;
		if (!ft_isspace(s[i]) && s[i])
			words++;
		while (!ft_isspace(s[i]) && s[i])
			i++;
	}
	return (words);
}

static char	*stringreturn(char const *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && !ft_isspace(s[i]))
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_free(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (NULL);
}

char	**ft_split_spaces(char const *s)
{
	char	**ret;
	int		i;
	int		string;

	string = wordcounter(s);
	i = 0;
	ret = malloc(sizeof(char **) * (string + 1));
	if (!ret || !s)
		return (NULL);
	while (i < string)
	{
		while (ft_isspace(*s))
			s++;
		ret[i] = stringreturn(s);
		if (ret[i] == NULL)
			return (ft_free(ret, i));
		s += ft_strlen(ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
