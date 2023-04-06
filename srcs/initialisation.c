/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/06 16:50:17 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fail(t_list *a)
{
	(void)a;
	write(2, "Error\n", 6);
	ft_lstclear(&a, ft_lstdel);
	exit(0);
}

t_list	*fill_a(char **av)
{
	t_list		*a;
	int			i;
	long int	num;

	num = ft_atoi_long(av[1]);
	i = 1;
	a = ft_lstnew((void *)num);
	while (av[++i])
	{
		num = ft_atoi_long(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_fail(a);
		ft_lstadd_back(&a, ft_lstnew((void *)num));
	}
	return (a);
}

t_list	*fill_a_checker(char **av)
{
	t_list		*a;
	int			i;
	char		**num_char;
	long int	num;

	num = ft_atoi_long(av[1]);
	i = 0;
	a = ft_lstnew((void *)num);
	num_char = ft_split(av[1], " ");
	while (num_char[++i])
	{
		num = ft_atoi_long(num_char[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			i = 0;
			while (num_char[i++])
				free(num_char[i]);
			exit_fail(a);
		}
		ft_lstadd_back(&a, ft_lstnew((void *)num));
	}
	i = 0;
	while (num_char[i++])
		free(num_char[i]);
	return (a);
}

long int	found_min(t_list **a)
{
	long int	value;
	t_list		*tmp;

	value = 2147483648;
	tmp = (*a);
	while (tmp)
	{
		if (tmp->index == (-1) && (long int)tmp->content < value)
			value = (long int)tmp->content;
		tmp = tmp->next;
	}
	return (value);
}

void	init_pos(t_list	**a)
{
	long int	min;
	t_list		*tmp;
	int			i;

	i = 1;
	tmp = (*a);
	min = found_min(a);
	while (tmp)
	{
		if (tmp->content == (void *)min)
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
