/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:22:31 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/11 11:28:20 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

int		push(t_list **a, t_list **b);
int		swap(t_list **a);
int		ss(t_list **a, t_list **b);
int		rotate(t_list **a);
int		rr(t_list **sa, t_list **b);
int		reverse_rotate(t_list **a);
int		rrr(t_list **a, t_list	**b);
void	read_stdout(t_list **a, t_list	**b);
t_list	*fill_a(char **av);
t_list	*fill_a_checker(char **av);
int		verif_sort(t_list **a);
void	manage_error(t_list **a, char **av, int ac);
int		verif_content(char **av);
int		verif_pair(t_list **a);
void	exit_fill(char **num_char);
#endif