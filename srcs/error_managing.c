/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:22:55 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/05 13:15:44 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_exit(t_list **a, char **av)
{
	if (verif_pair(a) == -1 || verif_content(av) == -1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

long int    *list_to_tab(t_list **a)
{
	t_list      *tmp;
	long int    *tab_val; 
	int         i;
	
	tmp = (*a);
	tab_val = malloc(sizeof(long int) * ft_lstsize(a));
	i = 0;
	while (tmp)
	{
		tab_val[i] = (long int)(tmp)->content;
		(tmp) = (tmp)->next;
		i++;
	}
	return (tab_val);
}

int	verif_pair(t_list **a)
{
	long int    *tab_val;
	long int	tmp_val;
	int         i;
	int         j;

	i = 0;
	j = 1;
	tab_val = list_to_tab(a);
	tmp_val = tab_val[0];
	while (i < ft_lstsize(a))
	{
		while (j < ft_lstsize(a))
		{
			if (tmp_val == tab_val[j])
				return (-1);
			if (tmp_val > INT_MAX || tmp_val < INT_MIN)
				return (-1);
			j ++;
		}
		i ++;
		tmp_val = tab_val[i];
		j = i + 1;
	}
	return (0);
}

int verif_content(char  **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[++i])
	{
		while (av[i][j])
		{
			if ((av[i][j] <= 57 && av[i][j] >= 48) || av[i][j] == 32
			|| av[i][j] == 45)
				j ++;
			else
				return (-1);
		}
		j = 0;
	}
	return (0);
}
