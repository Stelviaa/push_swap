/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:07:27 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/05 14:30:13 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

char	*push(t_list **a, t_list **b, int name);
char	*swap(t_list **a, int name);
char	*ss(t_list **a, t_list **b);
char	*rotate(t_list **a, int name);
char 	*rr(t_list **sa, t_list **b);
char	*reverse_rotate(t_list **a, int name);
char 	*rrr(t_list **a, t_list	**b);
void	algo(t_list **a, t_list **b, int ac);
t_list	*fill_a(char **av);
long int found_min(t_list **a);
void	init_pos(t_list	**a);
void	algo_bis(t_list **a, t_list **b);
void	algo_small_value(t_list **a);
void	algo_five(t_list **a, t_list **b, int limit);
void	algo_bis_five(t_list **a, t_list **b);
t_list	*fill_a_checker(char **av);
int		verif_pair(t_list **a);
void	manage_exit(t_list **a, char **av);
int		verif_sort(t_list **a);
int		verif_content(char  **av);
void	choose_algo(t_list *a, t_list *b);
#endif
