/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:41:02 by wmoughar          #+#    #+#             */
/*   Updated: 2023/08/25 19:05:12 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

bool	ft_check_first_line(t_map *map, int i)
{
	while (ft_space(map->map[0][i]))
		i++;
	while (map->map && map->map[0][i])
	{
		if (map->map[0][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_last_line(t_map *map, int i, int bottom_border)
{
	while (ft_space(map->map[bottom_border][i]))
		i++;
	while (map->map && map->map[bottom_border][i])
	{
		if (map->map[bottom_border][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_top_bottom_borders(t_map *map)
{
	int	i;
	int	bottom_border;

	i = 0;
	if (!ft_check_first_line(map, i))
		return (false);
	while (map->map && map->map[i])
		i++;
	i--;
	bottom_border = i;
	i = 0;
	if (!ft_check_last_line(map, i, bottom_border))
		return (false);
	return (true);
}

bool	ft_check_left_right_borders(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map && map->map[i])
	{
		j = 0;
		if (map->map[i] == NULL)
			return (false);
		if (map->map[i][0] == '\n' || map->map[i][0] == '\0')
			return (false);
		while (ft_space(map->map[i][j]))
			j++;
		if (map->map[i][j] != '1')
			return (false);
		while (j < ft_strlen(map->map[i]) - 1)
			j++;
		if (map->map[i][j] != '1')
			return (false);
		i++;
	}
	return (true);
}
