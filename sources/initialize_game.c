/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:31:21 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 18:52:17 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_initialize_window(t_map *map)
{
	map->mlx.ptr = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.ptr, WIDTH, HEIGHT, "cub3D");
	map->mlx_img.img = mlx_new_image(map->mlx.ptr, WIDTH, HEIGHT);
	map->mlx_img.addr = mlx_get_data_addr(map->mlx_img.img,
			&map->mlx_img.bits_per_pixel, &map->mlx_img.line_length,
			&map->mlx_img.endian);
}

void	ft_initialize_north_south_texts(t_map *map)
{
	map->north_text.img = mlx_xpm_file_to_image(map->mlx.ptr,
			map->north_text.path, &map->north_text.width,
			&map->north_text.height);
	map->north_text.addr = mlx_get_data_addr(map->north_text.img,
			&map->north_text.bits_per_pixel, &map->north_text.line_length,
			&map->north_text.endian);
	map->south_text.img = mlx_xpm_file_to_image(map->mlx.ptr,
			map->south_text.path, &map->south_text.width,
			&map->south_text.height);
	map->south_text.addr = mlx_get_data_addr(map->south_text.img,
			&map->south_text.bits_per_pixel, &map->south_text.line_length,
			&map->north_text.endian);
}

void	ft_initialize_east_west_texts(t_map *map)
{
	map->east_text.img = mlx_xpm_file_to_image(map->mlx.ptr,
			map->east_text.path, &map->east_text.width,
			&map->east_text.height);
	map->east_text.addr = mlx_get_data_addr(map->east_text.img,
			&map->east_text.bits_per_pixel, &map->east_text.line_length,
			&map->north_text.endian);
	map->west_text.img = mlx_xpm_file_to_image(map->mlx.ptr,
			map->west_text.path, &map->west_text.width,
			&map->west_text.height);
	map->west_text.addr = mlx_get_data_addr(map->west_text.img,
			&map->west_text.bits_per_pixel, &map->west_text.line_length,
			&map->north_text.endian);
}

void	ft_initialize_mlx_hook(t_map *map)
{
	mlx_hook(map->mlx.win, 2, 0, ft_key_controls, map);
	mlx_hook(map->mlx.win, 17, 0, (void *)ft_destroy_mlx, map);
	mlx_loop(map->mlx.ptr);
}

void	ft_initialize_game(t_map *map)
{
	ft_initialize_window(map);
	ft_initialize_north_south_texts(map);
	ft_initialize_east_west_texts(map);
	ft_raycast(map);
	ft_initialize_mlx_hook(map);
}
