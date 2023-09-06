/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:46:32 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 14:40:10 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_count_player(t_map *map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	find_p_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'E')
			{
				map->p_pos.x = j + 0.5;
				map->p_pos.y = i + 0.5;
				set_view_dir(map, map->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	set_view_dir(t_map *map, char c)
{
	if (c == 'E')
		map->view_dir = 0;
	else if (c == 'S')
		map->view_dir = M_PI / 2;
	else if (c == 'W')
		map->view_dir = M_PI;
	else if (c == 'N')
		map->view_dir = 3 * (M_PI / 2);
}
