/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:50:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/05 14:20:20 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_algo(t_list *a, t_list *b)
{
	if (ft_lstsize(&a) < 4)
		algo_small_value(&a);
	else if (ft_lstsize(&a)	== 4)
		algo_five(&a, &b, 3);
	else if (ft_lstsize(&a) == 5)
		algo_five(&a, &b, 4);
	else if (ft_lstsize(&a) < 101)
		algo(&a, &b, 12);
	else if (ft_lstsize(&a) < 501)
		algo(&a, &b, 30);
	while (b)
	{
		algo_bis(&a, &b);
	}
}

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
void	algo_small_value(t_list **a)
{
	int size;

	size = ft_lstsize(a);
	if ((*a)->index == 1 && (*a)->next->index == 3)
	{
		ft_printf("%s\n", swap(a, 1));
		ft_printf("%s\n", rotate(a, 1));
	}
	else if ((*a)->index == 3 && (*a)->next->index == 2)
	{
		ft_printf("%s\n", reverse_rotate(a, 1));
		ft_printf("%s\n", reverse_rotate(a, 1));
	}
	else if ((*a)->index == 2 && (*a)->next->index == 3)
		ft_printf("%s\n", reverse_rotate(a, 1));
	else if ((*a)->index == 3 && (*a)->next->index == 1)
		ft_printf("%s\n", rotate(a, 1));
	else if (((*a)->index == 2 && (*a)->next->index == 1))
		ft_printf("%s\n", swap(a, 1));
		
}

void	algo_five(t_list **a, t_list **b, int limit)
{
	int	i;
	int size_a;

	i = 1;
	size_a = ft_lstsize(a);
	while ((*a)->next->next)
	{
		if (i > 2 && (*b)->index > ft_lstsize(b))
			ft_printf("%s\n", rotate(b, 2));
		if ((*a)->index < limit)
		{
			ft_printf("%s\n", push(b, a, 2));
			i++;
		}
		else
			ft_printf("%s\n", rotate(a, 1));
	}
	if ((*a)->index > (*a)->next->index)
		ft_printf("%s\n", swap(a, 1));
}
