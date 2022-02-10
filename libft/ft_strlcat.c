/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:01:33 by lbenedar          #+#    #+#             */
/*   Updated: 2020/10/31 12:57:41 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*subdest;
	size_t	len;

	subdest = dst;
	len = 0;
	while (*subdest != 0)
	{
		subdest++;
		if (len < dstsize)
			len++;
	}
	while ((*src != 0) && (len + 1 < dstsize))
	{
		*subdest = *src;
		subdest++;
		src++;
		len++;
	}
	while (*src != 0)
	{
		len++;
		src++;
	}
	*subdest = 0;
	return (len);
}
