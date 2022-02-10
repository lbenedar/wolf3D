/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:31:52 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 13:57:32 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long long	*longdst;
	unsigned long long	*longsrc;
	unsigned char		*chrdst;
	unsigned char		*chrsrc;

	if ((!dst) && (!src))
		return (0);
	longdst = (unsigned long long*)dst;
	longsrc = (unsigned long long*)src;
	while (n >= 8)
	{
		*longdst++ = *longsrc++;
		n -= 8;
	}
	chrdst = (unsigned char*)longdst;
	chrsrc = (unsigned char*)longsrc;
	while (n--)
		*chrdst++ = *chrsrc++;
	return (dst);
}
