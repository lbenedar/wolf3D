/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:21:39 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 11:29:09 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*subs;

	i = 0;
	subs = (char*)s;
	while (s[i])
	{
		if ((subs[i]) == c)
			return (subs + i);
		i++;
	}
	if (subs[i] == c)
		return (subs + i);
	return (0);
}
