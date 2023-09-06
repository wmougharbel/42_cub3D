/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:13:11 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 14:38:34 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

bool	ft_correct_characters(char c )
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (false);
	return (true);
}

bool	ft_compare_top_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (map->map[i + 1])
		{
			if (ft_strlen(map->map[i]) < ft_strlen(map->map[i + 1]))
			{
				while (map->map[i + 1][j])
				{
					if (map->map[i + 1][j] != '1')
						return (false);
					j++;
				}
			}
		}
		i++;
	}
	return (true);
}

bool	ft_compare_bottom_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		if (map->map[i + 1])
		{
			while (map->map[i + 1][j])
				j++;
			if (ft_strlen(map->map[i]) > ft_strlen(map->map[i + 1]))
			{
				while (map->map[i][j])
				{
					if (map->map[i][j] != '1')
						return (false);
					j++;
				}
			}
		}
		i++;
	}
	return (true);
}

bool	ft_check_map_characters(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	if (!map || !map->map)
		return (false);
	count = ft_count_player(map);
	if (count > 1 || count == 0)
		return (false);
	while (map->map && map->map[i])
	{
		j = 0;
		while (ft_space(map->map[i][j]))
			map->map[i][j++] = '1';
		while (map->map[i][j])
		{
			if (!ft_correct_characters(map->map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_check_map(t_map *map)
{
	if (!map)
		return (ft_exit("Invalid Map!", map), false);
	if (!ft_compare_top_line(map))
		return (ft_exit("Map not surrounded with walls!", map), false);
	if (!ft_compare_bottom_line(map))
		return (ft_exit("Map not surrounded with walls!", map), false);
	if (!ft_check_top_bottom_borders(map))
		return (ft_exit("Incorrect top or bottom border!", map), false);
	if (!ft_check_left_right_borders(map))
		return (ft_exit("Incorrect left or right border!", map), false);
	if (!ft_check_map_characters(map))
		return (ft_exit("Invalid character in map!", map), false);
	find_p_position(map);
	return (true);
}
