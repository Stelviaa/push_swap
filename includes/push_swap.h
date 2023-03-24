/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <sforesti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:07:27 by sforesti          #+#    #+#             */
/*   Updated: 2023/03/24 10:20:02 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*push(t_list *a, t_list *bi, int name);
char	*swap(t_list *a, int name);
char	*ss(t_list *a, t_list *bi);
char	*rotate(t_list **a, int name);
char 	*rr(t_list **sa, t_list **b);
char	*reverse_rotate(t_list **a, int name);
char 	*rrr(t_list **a, t_list	**b);
#endif
