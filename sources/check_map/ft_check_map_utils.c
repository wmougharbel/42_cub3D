/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:03:14 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/03 15:03:12 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

bool	ft_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

char	*ft_find_map_in_file(char *line, int fd)
{
	while (line && ft_get_line_type(line) != __map)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	ft_store_map_in_array(t_map *map)
{
	int		fd;
	char	*line;
	char	*string;

	fd = open(map->filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (ft_putendl_fd("Empty file!", 2), exit(1));
	line = ft_find_map_in_file(line, fd);
	if (!line)
		return (ft_putendl_fd("Map not found!", 2), exit(1));
	string = ft_strdup("");
	while (line)
	{
		if (line[0] == '\n')
			return (ft_putendl_fd("Empty line in Map!", 2), exit(1));
		string = ft_gnl_strjoin(string, line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	map->map = ft_split(string, '\n');
	free(string);
}
