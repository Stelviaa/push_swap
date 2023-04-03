/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/03 18:55:51 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*swap(t_list **a, int name)
{
	t_list	*swap;

	if (!(*a) || !(*a)->next)
		return ("-1");
	swap = (*a)->next;
	swap = (*a);
	(*a) = swap;
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
	(void) ac;
	a = fill_a(av);
	init_pos(&a);
	if (ft_lstsize(&a) < 4)
		algo(&a, &b, 30);
	if (ft_lstsize(&a) < 101)
		algo(&a, &b, 12);
	if (ft_lstsize(&a) < 501)
		algo(&a, &b, 30);
	while (b)
		algo_bis(&a, &b);
	ft_lstclear(&a, ft_lstdel);
	system("leaks push_swap");
	return (0);
}
