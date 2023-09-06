/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:49:58 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/06 18:44:39 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_key_controls(int key, t_map *map)
{
	double	move_step;

	move_step = 0.5;
	if (key == 53)
	{
		ft_destroy_mlx(map);
		exit (0);
	}
	else if (key == ARROW_LEFT)
	{
		map->view_dir = fmod(map->view_dir - (0.08 * M_PI),
				2 * M_PI);
		if (map->view_dir < 0)
			map->view_dir += 2 * M_PI;
		ft_raycast(map);
	}
	else if (key == ARROW_RIGHT)
	{
		map->view_dir = fmod(map->view_dir + (0.08 * M_PI),
				2 * M_PI);
		ft_raycast(map);
	}
	arrow_movements(key, map, move_step);
	return (0);
}

void	key_handler(int key, t_map *m, double move_step)
{
	if (key == KEY_W)
	{
		m->new_pos.x = m->p_pos.x + cos(m->view_dir) * move_step;
		m->new_pos.y = m->p_pos.y + sin(m->view_dir) * move_step;
	}
	else if (key == KEY_S)
	{
		m->new_pos.x = m->p_pos.x - cos(m->view_dir) * move_step;
		m->new_pos.y = m->p_pos.y - sin(m->view_dir) * move_step;
	}
	else if (key == KEY_A)
	{
		m->new_pos.x = m->p_pos.x + cos(m->view_dir - M_PI / 2) * move_step;
		m->new_pos.y = m->p_pos.y + sin(m->view_dir - M_PI / 2) * move_step;
	}
	else if (key == KEY_D)
	{
		m->new_pos.x = m->p_pos.x - cos(m->view_dir - M_PI / 2) * move_step;
		m->new_pos.y = m->p_pos.y - sin(m->view_dir - M_PI / 2) * move_step;
	}
}

void	arrow_movements(int key, t_map *map, double move_step)
{
	key_handler(key, map, move_step);
	if (map->map[(int)map->new_pos.y][(int)map->new_pos.x] != '1')
	{
		map->p_pos.x = map->new_pos.x;
		map->p_pos.y = map->new_pos.y;
		ft_raycast(map);
	}
}
