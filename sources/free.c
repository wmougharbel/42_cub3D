/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:01:42 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 18:52:17 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_free_split_string(char **string)
{
	int	i;

	i = 0;
	while (string[i])
		free(string[i++]);
	free(string);
}

void	ft_free_map_struct(t_map *map)
{
	if (!map)
		return ;
	if (map->map)
		ft_free_split_string(map->map);
	ft_free_map_textures(map);
	free(map);
}

void	ft_free_map_textures(t_map *map)
{
	if (map->north_text.path)
		free(map->north_text.path);
	if (map->south_text.path)
		free(map->south_text.path);
	if (map->west_text.path)
		free(map->west_text.path);
	if (map->east_text.path)
		free(map->east_text.path);
}

void	ft_exit(char *message, t_map *map)
{
	if (map)
		ft_free_map_struct(map);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	ft_destroy_mlx(t_map *map)
{
	mlx_destroy_image(map->mlx.ptr, map->mlx_img.img);
	mlx_destroy_window(map->mlx.ptr, map->mlx.win);
	ft_free_map_struct(map);
	exit(0);
}
