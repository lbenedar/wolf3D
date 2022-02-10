/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:07:45 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/17 14:27:00 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_fillsplit(char const *s, char c, char **fillarray)
{
	size_t	i;
	int		num;
	int		first;

	i = 0;
	num = 0;
	first = 0;
	while (s[i])
	{
		if ((s[i] == c) && (first != -1))
		{
			if (!(fillarray[num] = ft_strndup(s + first, i - first)))
				return (0);
			first = -1;
			num++;
		}
		else if ((s[i] != c) && (first == -1))
			first = i;
		i++;
	}
	if ((i > 0) && (s[i - 1] != c))
		if (!(fillarray[num] = ft_strndup(s + first, i - first)))
			return (0);
	return (1);
}

static size_t	ft_splitnum(char const *s, char c)
{
	size_t	i;
	size_t	num;

	if (!(*s))
		return (0);
	i = 0;
	num = 0;
	if (s[i])
		num++;
	while (s[i])
	{
		if (s[i] == c)
			if ((s[i + 1] != c) && (s[i + 1] != 0))
				num++;
		i++;
	}
	return (num);
}

static	char	**ft_clean(char **array)
{
	char **subarray;

	if (!array)
		return (0);
	subarray = array;
	while (!(*subarray))
	{
		free(*subarray);
		subarray++;
	}
	free(array);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	size_t	num;
	char	**array;

	if (!s)
		return (0);
	while ((*s) && (*s == c))
		s++;
	num = ft_splitnum(s, c);
	if (!(array = ft_calloc(sizeof(char*), (num + 1))))
		return (0);
	if (num)
		if (!ft_fillsplit(s, c, array))
			return (ft_clean(array));
	return (array);
}
