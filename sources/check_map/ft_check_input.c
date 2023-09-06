/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:29:06 by wmoughar          #+#    #+#             */
/*   Updated: 2023/08/18 10:52:24 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

bool	ft_check_arguments(int argc)
{
	if (argc != 2)
	{
		ft_putendl_fd("Incorrect number of arguments!", STDERR_FILENO);
		printf("Argument 1: ./cub3D\n");
		printf("Argument 2: Map with .cub extension\n");
		return (false);
	}
	return (true);
}

bool	ft_extension_is_cub(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (!(argv[i - 4] == '.' && argv[i - 3] == 'c'
			&& argv[i - 2] == 'u' && argv[i - 1] == 'b'))
	{
		ft_putendl_fd("Map extension should be .cub!", STDERR_FILENO);
		return (false);
	}
	return (true);
}

bool	ft_check_input(int argc, char *argv)
{
	if (!ft_check_arguments(argc))
		return (false);
	if (!ft_extension_is_cub(argv))
		return (false);
	return (true);
}
