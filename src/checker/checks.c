/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:41:05 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/02 23:44:59 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Print the mandatory objects[A, L, C] message.
*/
static int	prt_error(void)
{
	int	out;

	out = write(2, "The file does not has All Mandatory Objects\n", 44);
	out += write(2, "Ambient Light(A), Light(L) and Camera(C)\n", 42);
	return (out);
}

static char	*read_loop(char *line, int fd, t_vec3 *elem)
{
	char	**content;

	content = ft_split(line, ' ');
	if (ft_strcmp(content[0], "A") == 0)
		elem->x ++;
	else if (ft_strcmp(content[0], "L") == 0)
		elem->y++;
	else if (ft_strcmp(content[0], "C") == 0)
		elem->z++;
	ft_array_free(content, ft_array_size(content));
	free(line);
	line = get_next_line(fd);
	return (line);
}

/*
** Check if the file has the mandatory objects[A, L, C]
*/
int	validate_scene_file(char *filename)
{
	char	*line;
	int		fd;
	t_vec3	elem;

	elem.x = 0;
	elem.y = 0;
	elem.z = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "File Error\n", 12));
	line = get_next_line(fd);
	while (line)
		line = read_loop(line, fd, &elem);
	free(line);
	if (elem.x < 1 || elem.y < 1 || elem.z < 1)
		return (prt_error());
	else if (elem.x > 1 || elem.y > 1 || elem.z > 1)
		return (write(2, "Error: Duplicated Object\n", 26));
	return (0);
}
