/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:13:56 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/11 11:28:47 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	exec_inst(char *instr, t_list **a, t_list **b)
{
	if (!ft_strcmp(instr, "sa\n"))
		swap(a);
	else if (!ft_strcmp(instr, "sb\n"))
		swap(b);
	else if (!ft_strcmp(instr, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(instr, "pa\n"))
		push(a, b);
	else if (!ft_strcmp(instr, "pb\n"))
		push(b, a);
	else if (!ft_strcmp(instr, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(instr, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(instr, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(instr, "rra\n"))
		reverse_rotate(a);
	else if (!ft_strcmp(instr, "rrb\n"))
		reverse_rotate(b);
	else if (!ft_strcmp(instr, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	verif_sort(t_list **a)
{
	t_list	*tmp;

	tmp = (*a);
	while (tmp->next)
	{
		if ((long int)tmp->content > (long int)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	manage_exit(char *inst, t_list	**a, t_list **b)
{
	if (verif_sort(a) && !ft_lstsize(b))
	{
		ft_printf("OK\n");
		free(inst);
		ft_lstclear(a, ft_lstdel);
		exit(0);
	}
	else if (!verif_sort(a) || ft_lstsize(b) > 0)
	{
		ft_printf("KO\n");
		free(inst);
		ft_lstclear(a, ft_lstdel);
		if (ft_lstsize(b))
			ft_lstclear(b, ft_lstdel);
		exit(0);
	}
	return (0);
}

void	read_stdout(t_list **a, t_list **b)
{
	char	*inst;
	int		i;
	int		statut;
	int		j;

	i = 0;
	inst = malloc(sizeof(char) * 4);
	j = read(STDIN_FILENO, inst, 4);
	statut = 0;
	while (j)
	{
		statut = exec_inst(inst, a, b);
		if (!statut)
		{
			ft_printf("Error\n");
			free(inst);
			exit(0);
		}
		j = read(STDIN_FILENO, inst, 4);
	}
	manage_exit(inst, a, b);
}

void	exit_fill(char **num_char)
{
	int	i;

	i = -1;
	while (num_char[++i])
		free(num_char[i]);
	free(num_char);
}
