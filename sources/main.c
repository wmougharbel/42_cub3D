/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:42:03 by wmoughar          #+#    #+#             */
/*   Updated: 2023/09/07 16:38:48 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../includes/cub.h"

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	map->filename = argv[1];
	if (!ft_check_input(argc, argv[1]))
		return (1);
	if (!ft_get_token_type(map))
		return (1);
	if (!ft_check_texture(map))
		return (1);
	ft_initialize_game(map);
	ft_free_map_struct(map);
	return (0);
}
