/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/03 14:26:37 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft.h"

t_list	*fill_a(char **av)
{
	t_list	*a;
	int		i;
	long int num;

	num = ft_atoi(av[1]);
	i = 1;
	a = ft_lstnew((void*)num);
	while (av[++i])
	{
		num = ft_atoi(av[i]);
		ft_lstadd_back(&a, ft_lstnew((void*)num));
	}
	return (a);
}

long int found_min(t_list **a)
{
    long int    value;
	t_list	*tmp;
    
    value = 2147483647;
	tmp = (*a);
    while (tmp)
    {
        if (tmp->index == (-1) && tmp->content < (void*)value)
            value = (long int)tmp->content;
        tmp = tmp->next;
    }
    return (value);
}

void	init_pos(t_list	**a)
{
	long int min;
	t_list	*tmp;
	int i;

	i = 1;
	tmp = (*a);
	min = found_min(a);	
	while (tmp)
	{
		if (tmp->content == (void*)min)
		{
			tmp->index = i;
			min = found_min(a);
			tmp = (*a);
			i++;
		}
		else
			tmp = tmp->next;
	}	
}