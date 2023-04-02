/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:31:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/02 12:16:38 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "libft.h"

t_list	*fill_a(char **av)
{
	t_list	*a;
	int		i;
	int num;

	num = ft_atoi(av[1]);
	i = 2;
	a = ft_lstnew(*(void**)&num);
	while (av[i])
	{
		num = ft_atoi(av[i]);
		ft_lstadd_back(&a, ft_lstnew(*(void**)&num));
		i ++;
	}
	return (a);
}