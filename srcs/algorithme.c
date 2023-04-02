/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:50:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/02 16:08:38 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int *found(t_list **a)
{
    long int    *value;
	t_list	*tmp;
	long int i;
    
	value = malloc(sizeof(long int) * 2);
    value[0] = (long int)(*a)->content;
	value[1] = 0;
	i = 0;
	tmp = (*a);
    tmp = tmp->next;
    while (tmp)
    {
        if (tmp->content < (void*)value[0])
		{
            value[0] = (long int)tmp->content;
			value[1] = i;
		}
        tmp = tmp->next;
		i++;
    }
    return (value);
}

void	push_on_b(t_list **a, t_list **b, int ac)
{
    long int *value;

    value = found(a);
	//ft_printf ("choose_ins:%d", choose_ins(a));
	while (value[0] != (long int)((*a)->content))
	{
		if ((int)value[1] < (ac - 2) / 2)
			ft_printf("%s\n",rotate(a, 1));
		else if ((int)value[1] > (ac - 2) / 2)
			ft_printf("%s\n",reverse_rotate(a, 1));
			
	}
	ft_printf("%s\n",push(b, a, 2));
}

void	algo(t_list **a, t_list **b, int ac)
{
	while ((*a))
	{
		push_on_b(a, b, ac);
	}/*
	while ((*b))
	{
		ft_printf("valb:%d\n", (int)(*b)->content);
		(*b) = (*b)->next;
	}*/
	while ((*b))
	{
		ft_printf("%s\n",push(a, b, 1));
	}	
}