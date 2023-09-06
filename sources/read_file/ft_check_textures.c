/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:26:14 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 19:44:25 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_count_commas(char *color)
{
	int	count;

	count = 0;
	while (*color)
	{
		if (*color == ',')
			count++;
		color++;
	}
	return (count);
}

bool	ft_texture_exist(t_map *map)
{
	if (!map->north_text.path)
		return (false);
	if (!map->south_text.path)
		return (false);
	if (!map->west_text.path)
		return (false);
	if (!map->east_text.path)
		return (false);
	return (true);
}

bool	ft_correct_texture_path(t_map *map)
{
	int	fd;

	fd = open(map->north_text.path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	fd = open(map->south_text.path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	fd = open(map->east_text.path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	fd = open(map->west_text.path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	ft_correct_texture_path_end(char *texture)
{
	int	len;

	len = ft_strlen(texture);
	if (!(texture[len - 4] == '.' && texture[len - 3] == 'x'
			&& texture[len - 2] == 'p' && texture[len - 1] == 'm'))
		return (false);
	return (true);
}

bool	ft_check_texture(t_map *map)
{
	if (!ft_texture_exist(map))
		return (ft_exit("Missing texture!", map), false);
	if (!ft_correct_texture_path(map))
		return (ft_exit("Texture path doesn't exist!", map), false);
	if (!ft_correct_texture_path_end(map->north_text.path))
		return (ft_exit("Texure path should end with .xpm!", map), false);
	if (!ft_correct_texture_path_end(map->south_text.path))
		return (ft_exit("Texure path should end with .xpm!", map), false);
	if (!ft_correct_texture_path_end(map->west_text.path))
		return (ft_exit("Texure path should end with .xpm!", map), false);
	if (!ft_correct_texture_path_end(map->east_text.path))
		return (ft_exit("Texure path should end with .xpm!", map), false);
	return (true);
}
