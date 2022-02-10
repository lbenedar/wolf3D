/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:01:57 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 11:22:29 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*chrs;

	i = 0;
	chrs = (char*)s;
	while (i < n)
	{
		if (chrs[i] == c)
			return ((void*)(s + i));
		i++;
	}
	return (0);
}
