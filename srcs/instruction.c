/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/03 13:19:31 by sforesti         ###   ########.fr       */
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
	//ft_printf("%s\n", swap(&a, 1));
	//algo(&a, &b, ac);
	init_pos(&a);
	//printf("ac:%d", ac);
//	write(1,"a", 1);
	//reverse_rotate(&a, 1);	
//	write(1,"b", 1);
	while (a)
	{
		printf("vali:%d index:%d\n", (int)a->content, a->index);
		a = a->next;
	}
	//printf("valb:%d\n", (int)b->content);
	//ft_lstclear(&a, ft_lstdel);
	//system("leaks push_swap");
	return (0);
}










