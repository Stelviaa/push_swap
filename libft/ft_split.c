/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:52:17 by sforesti          #+#    #+#             */
/*   Updated: 2023/02/18 19:11:53 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_is_in_charset(str[i], charset) && str[i])
			i++;
		if (!ft_is_in_charset(str[i], charset) && str[i])
		{
			count++;
			while (!ft_is_in_charset(str[i], charset) && str[i])
					i++;
		}
	}
	return (count);
}

char	*ft_fill(char *str, int start, int end)
{
	int		i;
	int		size;
	char	*fill_str;

	i = 0;
	size = end - start;
	fill_str = malloc(sizeof(char) * size + 1);
	while (start < end)
		fill_str[i++] = str[start++];
	fill_str[i] = '\0';
	return (fill_str);
}

char	**ft_fill_strs(char *str, char *charset, char **rt_str)
{
	int	i;
	int	s;
	int	e;
	int	index;

	i = 0;
	s = 0;
	e = 0;
	index = 0;
	while (str[i])
	{
		while (ft_is_in_charset(str[i], charset) && str[i])
			i++;
		s = i;
		while (!ft_is_in_charset(str[i], charset) && str[i])
			i++;
		e = i;
		while (ft_is_in_charset(str[i], charset) && str[i])
			i++;
		rt_str[index++] = ft_fill(str, s, e);
	}
	return (rt_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**rt_str;
	int		i;

	i = 0;
	if (charset[0] == '\0' && str[0] != '\0')
	{
		rt_str = malloc(sizeof(char *) * 2);
		while (str[i])
			i++;
		rt_str[0] = "\0";
		rt_str[1] = malloc(-1);
		return (rt_str);
	}
	if (str[0] == '\0')
	{
		rt_str = malloc(sizeof(char *));
		rt_str[0] = malloc(-1);
	}
	else
	rt_str = malloc(sizeof(char *) * ft_count_words(str, charset) + 1);
	rt_str = ft_fill_strs(str, charset, rt_str);
	rt_str[ft_count_words(str, charset)] = malloc(-1);
	return (rt_str);
}
