/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:54:53 by amurawsk          #+#    #+#             */
/*   Updated: 2023/09/06 18:59:20 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	raycast_reset(t_map *map)
{
	map->map_check.x = map->ray_pos.x;
	map->map_check.y = map->ray_pos.y;
	map->ray_length.x = 0;
	map->ray_length.y = 0;
	map->distance = 0.0;
}

void	color_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = map->mlx_img.addr + (y * map->mlx_img.line_length + x
				* (map->mlx_img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_color(t_texture *text, double text_x, double text_y)
{
	int				x;
	int				y;
	int				offset;
	unsigned int	*texel;

	x = (int)(text_x * text->width);
	y = (int)(text_y * text->height);
	offset = (y * text->line_length) + (x * (text->bits_per_pixel / 8));
	texel = (unsigned int *)(text->addr + offset);
	return (*texel);
}

int	firing_ray(t_map *map)
{
	while (map->distance < MAX_DISTANCE)
	{
		if (map->ray_length.x < map->ray_length.y)
		{
			map->map_check.x += map->step.x;
			map->distance = map->ray_length.x;
			map->ray_length.x += map->step_size.x;
			map->side = map->sides.x;
		}
		else
		{
			map->map_check.y += map->step.y;
			map->distance = map->ray_length.y;
			map->ray_length.y += map->step_size.y;
			map->side = map->sides.y;
		}
		if (map->map[map->map_check.y][map->map_check.x] == '1')
			return (1);
	}
	return (0);
}
