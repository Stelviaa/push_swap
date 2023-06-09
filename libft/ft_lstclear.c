/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:24:21 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/21 11:42:06 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l_bis;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		l_bis = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = l_bis;
	}
	lst = NULL;
}
