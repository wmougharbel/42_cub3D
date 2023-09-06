/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:10:55 by wmoughar          #+#    #+#             */
/*   Updated: 2023/08/29 18:31:57 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_rgb_to_hexadecimal(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

void	ft_convert_color_to_hex(t_map *map)
{
	map->floor_color = ft_rgb_to_hexadecimal(map->floor[0], map->floor[1],
			map->floor[2]);
	map->ceiling_color = ft_rgb_to_hexadecimal(map->ceiling[0], map->ceiling[1],
			map->ceiling[2]);
}
