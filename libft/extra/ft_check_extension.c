/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:16:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/20 22:20:52 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/*
@brief Check if the file has the indicated extension
@param filename: name of the file
@param ext: extension to check
@return 1 if the file has the indicated extension, 0 otherwise
*/
int	ft_check_extension(char *filename, char *ext)
{
	int	len_str;

	len_str = ft_strlen(filename);
	filename = &filename[len_str - ft_strlen(ext)];
	if (!ft_strcmp(filename, ext))
		return (1);
	return (0);
}
