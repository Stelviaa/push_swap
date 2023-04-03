/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:50:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/03 17:57:01 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_list **a, t_list **b, int size)
{
	int	i;

	i = 1;
	while ((*a))
	{
		if (i > 2 && (*b)->index > ft_lstsize(b))
		{
			ft_printf("%s\n", rotate(b, 2));
			//tmp = (*a);
			//i++;
		}
		if ((*a)->index <= size + i)
		{
			ft_printf("%s\n", push(b, a, 2));
			i++;
		}
		else
			ft_printf("%s\n", rotate(a, 1));
	}
}

void	algo_bis(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		size;
	int i;

	tmp = (*b);
	size = ft_lstsize(b);
	i = 0;
	while (tmp->index != size)
	{
			tmp = tmp->next;
			i ++;
	}
	if (i >= size / 2)
		while((*b)->index != size)
			ft_printf("%s\n", reverse_rotate(b, 2));
	if (i < size / 2)
		while((*b)->index != size)
			ft_printf("%s\n", rotate(b, 2));
	ft_printf("%s\n", push(a, b, 1));
}
/*
if (b->index >lenb)
	rb*/