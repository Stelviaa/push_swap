/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:20:23 by sforesti          #+#    #+#             */
/*   Updated: 2023/03/24 10:27:09 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate(t_list **a, int name)
{
	t_list	*begin_a;

	begin_a = *a;
	ft_lstadd_back(a, ft_lstnew(begin_a->content));
	begin_a = (*a)->next;
	free(*a);
	(*a) = begin_a;
	if (name == 1)
		return ("rra");
	else if (name == 2)
		return ("rrb");
	return ("0");
}

char *rr(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	return ("rr");
}

char	*reverse_rotate(t_list **a, int name)
{
	t_list	*l_bis;
	t_list	*swap;

	l_bis = ft_lstlast(*a);
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

char *rrr(t_list **a, t_list	**b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	return ("rrr");
}
