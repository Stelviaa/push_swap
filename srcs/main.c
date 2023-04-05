/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:44:11 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/05 13:10:32 by sforesti         ###   ########.fr       */
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
	{ // ajouter condition de liste non triee
		algo_bis(&a, &b);
	}
}

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac == 1)
		return (0);
	if (ac > 2)
		a = fill_a(av);
	else if (ac == 2)
		a = fill_a_checker(av);
	manage_exit(&a, av);
	init_pos(&a);
   	if(verif_sort(&a) == 1)
	{
		ft_lstclear(&a, ft_lstdel);
		return (0);
	}
	choose_algo(a, b);
	ft_lstclear(&a, ft_lstdel);
	return (0);
}