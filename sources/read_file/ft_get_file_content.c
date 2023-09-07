/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:57:15 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/07 16:39:45 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_init_content(t_map *map)
{
	map->north_text.path = NULL;
	map->south_text.path = NULL;
	map->east_text.path = NULL;
	map->west_text.path = NULL;
	map->floor[0] = 0;
	map->floor[1] = 0;
	map->floor[2] = 0;
	map->ceiling[0] = 0;
	map->ceiling[1] = 0;
	map->ceiling[2] = 0;
}

bool	ft_get_token_type(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening file!");
	ft_init_content(map);
	line = get_next_line(fd);
	while (line)
	{
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_store_in_corresponding_array(map, line, ft_get_line_type(line));
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	ft_store_map_in_array(map);
	if (!ft_check_map(map))
		return (false);
	close(fd);
	return (true);
}

int	ft_get_line_type(char *line)
{
	int	type;

	type = __map;
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO	", 3))
		type = __north_text;
	else if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO	", 3))
		type = __south_text;
	else if (!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE	", 3))
		type = __west_text;
	else if (!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA	", 3))
		type = __east_text;
	else if (!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C	", 2))
		type = __ceiling_color;
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F	", 2))
		type = __floor_color;
	else if (!ft_strncmp(line, "11", 2))
		type = __map;
	else if (line && line[0] == '\n')
		type = __empty_space;
	return (type);
}

void	ft_store_in_corresponding_array(t_map *map, char *texture, int type)
{
	if (type == __north_text)
		map->north_text.path = ft_strtrim(texture, "NO 	");
	else if (type == __south_text)
		map->south_text.path = ft_strtrim(texture, "SO 	");
	else if (type == __east_text)
		map->east_text.path = ft_strtrim(texture, "EA 	");
	else if (type == __west_text)
		map->west_text.path = ft_strtrim(texture, "WE 	");
	else if (type == __floor_color || type == __ceiling_color)
		ft_store_colors_in_arrays(map, type, texture);
	ft_convert_color_to_hex(map);
}

void	ft_store_colors_in_arrays(t_map *map, int type, char *color)
{
	char	**string;
	char	*trim;

	if (ft_count_commas(color) != 2)
		return (ft_putendl_fd("Invalid Color!", 2), exit(1));
	string = ft_split(color, ',');
	trim = NULL;
	if (type == __floor_color)
	{
		trim = ft_strtrim(string[0], "F 	");
		map->floor[0] = ft_atoi(trim);
		map->floor[1] = ft_atoi(string[1]);
		map->floor[2] = ft_atoi(string[2]);
	}
	else if (type == __ceiling_color)
	{
		trim = ft_strtrim(string[0], "C 	");
		map->ceiling[0] = ft_atoi(trim);
		map->ceiling[1] = ft_atoi(string[1]);
		map->ceiling[2] = ft_atoi(string[2]);
	}
	if (trim)
		free(trim);
	ft_free_split_string(string);
}
