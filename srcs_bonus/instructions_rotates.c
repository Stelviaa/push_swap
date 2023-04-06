/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:20:23 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/06 12:01:54 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_list **a)
{
	t_list	*tmp;
	t_list	*begin_l;

	begin_l = (*a)->next;
	tmp = (*a);
	(tmp)->next = NULL;
	ft_lstlast(&begin_l)->next = tmp;
	(*a) = begin_l;
	return (0);
}

int	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	return (0);
}

int	reverse_rotate(t_list **a)
{
	t_list	*l_bis;
	t_list	*swap;

	l_bis = ft_lstlast(a);
	swap = (*a);
	while ((*a)->next->next)
		(*a) = (*a)->next;
	(*a)->next = NULL;
	l_bis->next = swap;
	(*a) = l_bis;
	return (0);
}

int	rrr(t_list **a, t_list	**b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (0);
}
