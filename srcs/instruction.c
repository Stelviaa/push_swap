/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/04 16:43:15 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	
	if (!b)
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

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac > 2)
		a = fill_a(av);
	else if (ac == 2)
		a = fill_a_checker(av);
	init_pos(&a);
	if (ft_lstsize(&a) < 4)
		algo_small_value(&a);
	else if (ft_lstsize(&a) < 6)
		algo_five(&a, &b);
	else if (ft_lstsize(&a) < 101)
		algo(&a, &b, 12);
	else if (ft_lstsize(&a) < 501)
		algo(&a, &b, 30);
	while (b)
	{ // ajouter condition de liste non triee
		algo_bis(&a, &b);
	}
	ft_lstclear(&a, ft_lstdel);
	return (0);
}
