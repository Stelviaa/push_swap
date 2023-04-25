/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:44:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/25 11:06:47 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_exit(char **av, int ac)
{
	int	i;

	i = 0;
	if (ac == 1 || av[1][0] == '\0')
		exit (0);
	while (av[1][i] == 32)
		i ++;
	if (av[1][i] == '\0')
	{
		write (2, "Error\n", 6);
		exit (0);
	}
	return (0);
}

int	initialisation(t_list *a, int ac, char **av)
{
	if (ac == 1)
		return (0);
	manage_exit(&a, av, ac);
	init_pos(&a);
	if (verif_sort(&a) == 1)
	{
		ft_lstclear(&a, ft_lstdel);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	start_exit(av, ac);
	if (ac > 2)
		a = fill_a(av);
	else if (ac == 2)
		a = fill_a_checker(av);
	if (!initialisation(a, ac, av))
		return (0);
	if (ft_lstsize(&a) < 4)
		algo_small_value(&a);
	else if (ft_lstsize(&a) == 4)
		algo_five(&a, &b, 3);
	else if (ft_lstsize(&a) == 5)
		algo_five(&a, &b, 4);
	else if (ft_lstsize(&a) < 101)
		algo(&a, &b, 12);
	else if (ft_lstsize(&a) < 501)
		algo(&a, &b, 30);
	while (b)
		algo_bis(&a, &b);
	return (0);
}
