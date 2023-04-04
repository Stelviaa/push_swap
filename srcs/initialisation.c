/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/04 18:43:23 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft.h"

t_list	*fill_a(char **av)
{
	t_list	*a;
	int		i;
	long int num;

	num = ft_atoi_long(av[1]);
	i = 1;
	a = ft_lstnew((void*)num);
	while (av[++i])
	{
		num = ft_atoi_long(av[i]);
		ft_lstadd_back(&a, ft_lstnew((void*)num));
	}
	return (a);
}

t_list	*fill_a_checker(char **av)
{
	t_list	*a;
	int i;
	char	**num_char;
	long int num;

	num = ft_atoi_long(av[1]);
	i = 0;
	a = ft_lstnew((void*)num);
	num_char = ft_split(av[1], " ");
	while (num_char[++i])
	{
		num = ft_atoi_long(num_char[i]);
		ft_lstadd_back(&a, ft_lstnew((void*)num));
	}
	i = 0;
	while (num_char[i++])
		free(num_char[i]);
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