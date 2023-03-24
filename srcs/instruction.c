/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <sforesti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/03/21 15:13:48 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	swap(t_list *a)
{
	t_list *swap;

	swap = malloc(sizeof(t_list));
	if (a == NULL || a->next == NULL)
		return (-1);
	swap->content = a->content;
       	a->content = a->next->content;
	a->next->content = swap->content;
	return (0);
}

int	ss(t_list *a, t_list *b)
{
	swap(a);
	swap(b);
	return (0);
}

int	push(t_list *a, t_list *b)
{	
	t_list *swap;

	if (b == NULL)
		return (-1);
	swap = malloc(sizeof(t_list));
	swap->next = a;
	swap->content = b->content;
	a = swap;
	return (0);
}

int rotate(t_list **a)
{
	t_list	*begin_a;

	begin_a = *a;
	ft_lstadd_back(a, ft_lstnew(begin_a->content));
	begin_a = (*a)->next;
	free(*a);
	(*a) = begin_a;
	return (0);
}

int	reverse_rotate(t_list **a)
{
	t_list *l_bis;

	l_bis = ft_lstlast(*a);
	//printf("val:::::::::%d\n", (int)l_bis->content);
	return (0);
}

/*
t_list	**initialisation(char **av)
{
	
}*/

int main()
{
	t_list *a = ft_lstnew((void*)9);

	ft_lstadd_back(&a, ft_lstnew((void*)2));
	ft_lstadd_back(&a, ft_lstnew((void*)87));
	ft_lstadd_back(&a, ft_lstnew((void*)42));
//	write(1,"a", 1);
	reverse_rotate(&a);	
//	write(1,"b", 1);
	while (a)
	{
		printf("val:%d\n", (int)a->content);
		a = a->next;
	}
	return (0);
}










