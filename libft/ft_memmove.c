/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:48:08 by lbenedar          #+#    #+#             */
/*   Updated: 2020/10/31 12:57:12 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	size_t j;

	if ((!dst) && (!src))
		return (0);
	i = 0;
	j = (long)(dst - src);
	if ((j > 0) && (j < len))
	{
		len = len - j + 1;
		while (i < len)
		{
			((char*)dst)[len - i - 1] = ((char*)src)[len - i - 1];
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}
