/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:41:05 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/20 22:38:23 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

/*
** Print the mandatory objects[A, L, C] message.
*/
static int	element_error(t_vec3 elem)
{
	if (elem.x < 1 || elem.y < 1 || elem.z < 1)
	{
		write(2, "The file does not has All Mandatory Objects\n", 44);
		return (write(2, "Ambient Light(A), Light(L) and Camera(C)\n", 42));
	}
	else if (elem.x > 1 || elem.y > 1 || elem.z > 1)
		return (write(2, "Error: Duplicated Object\n", 26));
	return (0);
}

static void	free_error_file(char *line, char *raw_line, char **content)
{
	free(line);
	free (raw_line);
	ft_array_free(content, ft_array_size(content));
}

static int	validate_scene_loop(char *line, char *raw_line, t_vec3 *elem)
{
	static int	l_nbr = 0;
	char		**content;

	l_nbr++;
	if (!line || ft_strlen(line) == 0)
		;
	else
	{
		content = ft_split(line, ' ');
		if (!ft_check_line_data(content))
		{
			printf("[FILE CONFIG] Syntax Error: on line %d\n", l_nbr);
			free_error_file(line, raw_line, content);
			return (0);
		}
		if (ft_strcmp(content[0], "A") == 0)
			elem->x++;
		else if (ft_strcmp(content[0], "L") == 0)
			elem->y++;
		else if (ft_strcmp(content[0], "C") == 0)
			elem->z++;
		ft_array_free(content, ft_array_size(content));
	}
	return (1);
}

/*
** Check if the file has the mandatory objects[A, L, C]
*/
int	validate_scene_file(char *filename)
{
	char	*line;
	int		fd;
	t_vec3	elem;
	char	*raw_line;

	elem.x = 0;
	elem.y = 0;
	elem.z = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "File Error\n", 12));
	raw_line = get_next_line(fd);
	while (raw_line)
	{
		line = ft_strtrim(raw_line, "\n ");
		if (!validate_scene_loop(line, raw_line, &elem))
			return (1);
		free(line);
		free (raw_line);
		raw_line = get_next_line(fd);
	}
	if (element_error(elem))
		return (1);
	return (0);
}

bool	ft_check_line_data(char **content)
{
	int	error;

	error = 0;
	if (ft_strcmp(content[0], "A") == 0)
		error = ambient_light_data_check(content);
	else if (ft_strcmp(content[0], "C") == 0)
		error = camera_data_check(content);
	else if (ft_strcmp(content[0], "L") == 0)
		error = light_data_check(content);
	else if (ft_strcmp(content[0], "pl") == 0)
		error = plane_data_check(content);
	else if (ft_strcmp(content[0], "sp") == 0)
		error = sphere_data_check(content);
	else if (ft_strcmp(content[0], "cy") == 0 || \
			ft_strcmp(content[0], "cn") == 0)
		error = cylinder_data_check(content);
	else if (ft_strcmp(content[0], "CHECKBOARD") == 0)
		error = checkboard_data_check(content);
	else
		error = 0;
	return (error);
}
