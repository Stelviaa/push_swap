/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:07:27 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/02 13:39:02 by sforesti         ###   ########.fr       */
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
void	algo(t_list **a, t_list **b);
t_list	*fill_a(char **av);
#endif
