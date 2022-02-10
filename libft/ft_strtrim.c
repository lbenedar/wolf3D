/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:40:22 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/15 18:20:41 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_findstart(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;

	start = 0;
	while (s1[start])
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[start])
				break ;
			i++;
		}
		if (!set[i])
			break ;
		start++;
	}
	return (start);
}

static	size_t	ft_findend(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	end = 0;
	if (!s1[end])
		return (end);
	while (s1[end])
		end++;
	while (s1[--end])
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == s1[end])
				break ;
			i++;
		}
		if (!set[i])
			break ;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if ((!s1) || (!set))
		return (0);
	start = ft_findstart(s1, set);
	end = ft_findend(s1, set);
	return (ft_strndup(s1 + start, (end - start + 1)));
}
