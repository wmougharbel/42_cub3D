/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:38:43 by wmoughar          #+#    #+#             */
/*   Updated: 2023/01/22 12:38:43 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	if (*lst)
	{
		while (*lst)
		{
			next_node = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = next_node;
		}
		*lst = 0;
	}
}
