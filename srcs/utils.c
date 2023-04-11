/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:39:59 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/11 10:45:51 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_sort(t_list **a)
{
	t_list	*tmp;

	tmp = (*a);
	while (tmp->next)
	{
		if (tmp->index != tmp->next->index - 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	exit_fill(char **num_char)
{
	int	i;

	i = -1;
	while (num_char[++i])
		free(num_char[i]);
	free(num_char);
}
