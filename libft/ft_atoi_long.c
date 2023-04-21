/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:28:37 by sforesti          #+#    #+#             */
/*   Updated: 2023/04/11 14:12:56 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi_long(const char *str)
{
	int			i;
	int			negative;
	long int	nb;

	i = 0;
	negative = 1;
	nb = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i ++;
	}
	while (48 <= str[i] && str[i] <= 57 && str[i])
	{
		nb *= 10;
		nb += (str[i] - 48);
		i ++;
	}
	return (nb * negative);
}
