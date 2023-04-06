/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:20:23 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/06 12:26:27 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate(t_list **a, int name)
{
	t_list	*tmp;
	t_list	*begin_l;

	begin_l = (*a)->next;
	tmp = (*a);
	(tmp)->next = NULL;
	ft_lstlast(&begin_l)->next = tmp;
	(*a) = begin_l;
	if (name == 1)
		return ("ra");
	else if (name == 2)
		return ("rb");
	return ("0");
}

char	*rr(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	return ("rr");
}

char	*reverse_rotate(t_list **a, int name)
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
	if (name == 1)
		return ("rra");
	else if (name == 2)
		return ("rrb");
	return ("0");
}

char	*rrr(t_list **a, t_list	**b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	return ("rrr");
}
