/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:08:42 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 11:19:53 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*subs1;
	unsigned char	*subs2;

	i = 0;
	subs1 = (unsigned char*)s1;
	subs2 = (unsigned char*)s2;
	while (i < n)
	{
		if (subs1[i] - subs2[i])
			return (subs1[i] - subs2[i]);
		i++;
	}
	return (0);
}
