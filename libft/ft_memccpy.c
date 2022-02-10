/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:06:05 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 15:28:05 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*chrdst;
	unsigned char	*chrsrc;

	if ((!dst) && (!src))
		return (0);
	i = 0;
	chrsrc = (unsigned char*)src;
	chrdst = (unsigned char*)dst;
	while (i < n)
	{
		chrdst[i] = chrsrc[i];
		if (chrsrc[i] == (unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (0);
}
