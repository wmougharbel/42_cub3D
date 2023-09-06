/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:09:51 by wmoughar          #+#    #+#             */
/*   Updated: 2023/01/09 20:09:51 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_neg(int *n, int *sign, int *tmp)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*sign = -1;
		*tmp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*sign = -1;
		*n = *n * -1;
		*tmp = 0;
	}
	else if (*n >= 0)
	{
		*sign = 1;
		*tmp = 0;
	}
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

void	make_char(char *str, int len, int n, int tmp)
{
	while (n > 9)
	{
		str[len--] = (n % 10) + '0' + tmp;
		n /= 10;
		tmp = 0;
	}
	str[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int		sign;
	int		tmp;
	int		len;
	char	*str;

	ft_neg(&n, &sign, &tmp);
	len = ft_len(n);
	if (sign == -1)
	{
		str = malloc(sizeof(char) * (len + 2));
		if (!str)
			return (0);
		len++;
		str[0] = '-';
	}
	else
	{
		str = malloc (sizeof(char) * (len + 1));
		if (!str)
			return (0);
	}
	str[len--] = '\0';
	make_char(str, len, n, tmp);
	return (str);
}
