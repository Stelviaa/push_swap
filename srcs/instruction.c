/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/06 14:38:33 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap(t_list **a, int name)
{
	t_list	*swap;
	t_list	*swap2;
	t_list	*begin_l;

	if (!(*a) || !(*a)->next)
		return ("-1");
	swap2 = (*a)->next;
	begin_l = (*a)->next->next;
	swap = (*a);
	swap->next = begin_l;
	swap2->next = swap;
	(*a) = swap2;
	if (name == 1)
		return ("sa");
	else if (name == 2)
		return ("sb");
	return (0);
}

char	*ss(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	return ("ss");
}

char	*push(t_list **a, t_list **b, int name)
{	
	t_list	*tmp;

	if (!(*b))
		return ("-1");
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (name == 1)
		return ("pa");
	else if (name == 2)
		return ("pb");
	return (0);
}
