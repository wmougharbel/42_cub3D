/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:25:56 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 19:00:52 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw_textures(t_map *map, double wall_height, int y)
{
	if (map->side == WEST || map->side == EAST)
		map->text.x = map->ray_pos.y + map->distance * map->ray_dir.y;
	else
		map->text.x = map->ray_pos.x + map->distance * map->ray_dir.x;
	if (map->text.x < 0.0) 
		map->text.x = 1.0 - fmod(fabs(map->text.x), 1.0);
	if (map->text.x >= 1.0) 
		map->text.x = fmod(map->text.x, 1.0);
	map->text.y = (double)(y - ((HEIGHT / 2) \
			- (wall_height / 2))) / wall_height;
	if (map->text.y < 0.0) 
		map->text.y = 0.0;
	if (map->text.y >= 1.0)
		map->text.y = 1.0;
	if (map->side == EAST)
		map->text_clr = get_color(&map->east_text, map->text.x, map->text.y);
	if (map->side == WEST)
		map->text_clr = get_color(&map->west_text, map->text.x, map->text.y);
	if (map->side == SOUTH)
		map->text_clr = get_color(&map->south_text, map->text.x, map->text.y);
	if (map->side == NORTH)
		map->text_clr = get_color(&map->north_text, map->text.x, map->text.y);
}

void	draw_line(t_map *map, double ray_angle, int pixel_number)
{
	double			perp_ray_len;
	double			wall_height;
	int				y;

	perp_ray_len = map->distance * cos(ray_angle - map->view_dir);
	wall_height = HEIGHT / perp_ray_len;
	y = 0;
	while (y < ((HEIGHT / 2) - (wall_height / 2)))
		color_pixel_put(map, pixel_number, y++, map->ceiling_color);
	while ((y >= ((HEIGHT / 2) - (wall_height / 2))) \
				&& (y < ((HEIGHT / 2) + (wall_height / 2))))
	{
		draw_textures(map, wall_height, y);
		if (y >= HEIGHT)
			return ;
		color_pixel_put(map, pixel_number, y++, map->text_clr);
	}
	while (y < HEIGHT)
		color_pixel_put(map, pixel_number, y++, map->floor_color);
}

void	check_ray_value_y(t_map *map)
{
	if (map->ray_dir.y < 0)
	{
		map->step.y = -1;
		map->ray_length.y = (map->ray_pos.y - (float)map->map_check.y) \
			* map->step_size.y;
		map->sides.y = SOUTH;
	}
	else
	{
		map->step.y = 1;
		map->ray_length.y = ((float)(map->map_check.y + 1) - map->ray_pos.y) \
			* map->step_size.y;
		map->sides.y = NORTH;
	}
}

void	check_ray_value_x(t_map *map)
{
	if (map->ray_dir.x < 0)
	{
		map->step.x = -1;
		map->ray_length.x = (map->ray_pos.x - (float)map->map_check.x) \
			* map->step_size.x;
		map->sides.x = WEST;
	}
	else
	{
		map->step.x = 1;
		map->ray_length.x = ((float)(map->map_check.x + 1) - map->ray_pos.x) \
			* map->step_size.x;
		map->sides.x = EAST;
	}
	check_ray_value_y(map);
}

void	ft_raycast(t_map *map)
{
	double	current_ray_angle;
	double	step;

	map->pixel_number = 0;
	step = -0.75;
	while (map->pixel_number < WIDTH)
	{
		map->ray_pos = map->p_pos;
		map->fov = atan(step);
		current_ray_angle = map->view_dir + map->fov;
		map->ray_dir.x = cos(current_ray_angle);
		map->ray_dir.y = sin(current_ray_angle);
		map->step_size.x = sqrt(1 + (map->ray_dir.y / map->ray_dir.x) \
			* (map->ray_dir.y / map->ray_dir.x));
		map->step_size.y = sqrt(1 + (map->ray_dir.x / map->ray_dir.y) \
			* (map->ray_dir.x / map->ray_dir.y));
		raycast_reset(map);
		check_ray_value_x(map);
		if (firing_ray(map))
			draw_line(map, current_ray_angle, map->pixel_number);
		map->pixel_number++;
		step += 1.5 / WIDTH;
	}
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.win, map->mlx_img.img, 0, 0);
}
