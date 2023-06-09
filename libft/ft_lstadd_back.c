/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:15:16 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/11 12:59:02 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_bis;

	if (!(*lst))
		*lst = new;
	else
	{
		l_bis = ft_lstlast(lst);
		l_bis->next = new;
	}
}
