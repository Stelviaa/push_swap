/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:16:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/25 10:26:19 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;

	(void) ac;
	a = NULL;
	i = 0;
	if (ac == 1 || av[1][0] == '\0')
		return (0);
	if (ac > 2)
		a = fill_a(av);
	else if (ac == 2)
	{
		while (av[1][i] == 32)
			i ++;
		if (av[1][i] == '\0')
		{
			write (2, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		a = fill_a_checker(av);
	}
	manage_error(&a, av, ac);
	read_stdout(&a, &b);
}
