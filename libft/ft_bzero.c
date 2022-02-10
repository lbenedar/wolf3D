/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:56:25 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 13:50:31 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long long	*longb;
	unsigned char		*chrb;

	longb = (unsigned long long*)s;
	while (n >= 8)
	{
		*longb++ = 0;
		n -= 8;
	}
	chrb = (unsigned char*)longb;
	while (n--)
		*chrb++ = 0;
}
