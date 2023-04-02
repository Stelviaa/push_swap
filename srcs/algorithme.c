/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:50:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/02 15:04:13 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    *found(t_list **a)
{
    void    *value;
	t_list	*tmp;
    
    value = (*a)->content;
	tmp = (*a);
    tmp = tmp->next;
    while (tmp)
    {
        if (tmp->content < value)
            value = tmp->content;
        tmp = tmp->next;
    }
    return (value);
}

void	push_on_b(t_list **a, t_list **b)
{
    void *value;

    value = found(a);
	while (value != ((*a)->content))
		ft_printf("%s\n",rotate(a, 1));
	ft_printf("%s\n",push(b, a, 2));
}

void	algo(t_list **a, t_list **b)
{
	while ((*a))
	{
		push_on_b(a, b);
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