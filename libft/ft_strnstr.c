/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:59:50 by lbenedar          #+#    #+#             */
/*   Updated: 2020/10/31 12:58:01 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	subi;
	size_t	j;

	i = 0;
	if (!(*needle))
		return ((char*)haystack);
	while ((haystack[i] != 0) && (i < len))
	{
		j = 0;
		subi = i;
		while ((needle[j]) && (i + j < len))
		{
			if (needle[j] != haystack[subi])
				break ;
			subi++;
			j++;
		}
		if (!needle[j])
			break ;
		i++;
	}
	if ((haystack[i]) && (i < len))
		return ((char*)&haystack[i]);
	return (0);
}
