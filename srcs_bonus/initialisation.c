/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/05 14:46:31 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_fail(t_list *a)
{
	(void)a;
	ft_printf("Error\ncontent not int\n");
	ft_lstclear(&a, ft_lstdel);
	system("leaks push_swap");
	exit(0);
}

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
		if (num > INT_MAX || num < INT_MIN)
			exit_fail(a);
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
		if (num > INT_MAX || num < INT_MIN)
		{
			while (num_char[i++])
				free(num_char[i]);
			exit_fail(a);
		}
		ft_lstadd_back(&a, ft_lstnew((void*)num));
	}
	i = 0;
	while (num_char[i++])
		free(num_char[i]);
	return (a);	
}
