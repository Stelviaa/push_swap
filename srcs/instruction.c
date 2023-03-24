/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <sforesti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:03 by sforesti          #+#    #+#             */
/*   Updated: 2023/03/24 10:26:17 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*swap(t_list *a, int name)
{
	t_list *swap;

	swap = malloc(sizeof(t_list));
	if (!swap)
		return ("-1");
	if (a == NULL || a->next == NULL)
		return ("-1");
	swap->content = a->content;
       	a->content = a->next->content;
	a->next->content = swap->content;
	if (name == 1)
		return ("sa");
	else if (name == 2)
		return ("sb");
	return (0);
}

char	*ss(t_list *a, t_list *b)
{
	swap(a, 0);
	swap(b, 0);
	return ("ss");
}

char	*push(t_list *a, t_list *b, int name)
{	
	t_list *swap;

	if (!b)
		return ("-1");
	swap = malloc(sizeof(t_list));
	if (!swap)
		return ("-1");
	swap->next = a;
	swap->content = b->content;
	a = swap;
	if (name == 1)
		return ("pa");
	else if (name == 2)
		return ("pb");
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
	reverse_rotate(&a, 1);	
//	write(1,"b", 1);
	while (a)
	{
		printf("val:%d\n", (int)a->content);
		a = a->next;
	}
	return (0);
}










