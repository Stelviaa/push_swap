/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/05 17:48:49 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap(t_list **a)
{
	t_list	*swap;
	t_list	*swap2;
	t_list	*begin_l;

	if (!(*a) || !(*a)->next)
		return (-1);
	swap2 = (*a)->next;
	begin_l = (*a)->next->next;
	swap = (*a);
	swap->next = begin_l;
	swap2->next = swap;
	(*a) = swap2;
	return (0);
}


int	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	return (0);
}

int	push(t_list **a, t_list **b)
{	
	t_list	*tmp;
	
	if (!(*b))
		return (-1);
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	return (0);
}