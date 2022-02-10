/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:03:07 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 13:45:56 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long long	*longb;
	unsigned char		*chrb;
	unsigned long long	subc;

	longb = (unsigned long long*)b;
	if (len >= 8)
	{
		subc = (unsigned char)c;
		subc |= (unsigned char)c << 8;
		subc |= subc << 16;
		subc |= subc << 32;
		while (len >= 8)
		{
			*longb++ = subc;
			len -= 8;
		}
	}
	chrb = (unsigned char*)longb;
	while (len--)
		*chrb++ = (unsigned char)c;
	return (b);
}
