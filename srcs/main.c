/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:44:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/06 14:28:31 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac == 1 || (!av[1][0]))
		return (0);
	if (ac > 2)
		a = fill_a(av);
	else if (ac == 2)
		a = fill_a_checker(av);
	manage_exit(&a, av, ac);
	init_pos(&a);
	if (verif_sort(&a) == 1)
	{
		ft_lstclear(&a, ft_lstdel);
		return (0);
	}
	choose_algo(a, b);
	ft_lstclear(&a, ft_lstdel);
	return (0);
}
