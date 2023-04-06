/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:16:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/06 10:05:22 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int ac, char **av)
{
    t_list  *a;
    t_list  *b;

    (void) ac;
    (void) av;
    a = NULL;
    if (ac == 1)
		return (0);
	if (ac > 2)
		a = fill_a(av);
	else if (ac == 2)
		a = fill_a_checker(av);
    read_stdout(&a, &b);
}