/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:12 by wmoughar          #+#    #+#             */
/*   Updated: 2022/12/23 13:35:12 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*t;

	t = (const char *)s;
	i = 0;
	while (i < n && t[i] != (const char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)&t[i]);
}
