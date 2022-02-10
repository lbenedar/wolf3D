/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:42:14 by lbenedar          #+#    #+#             */
/*   Updated: 2020/10/31 16:10:40 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*newstr;
	size_t	len;

	len = 0;
	while ((s[len]) && (len < n))
		len++;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	len = 0;
	while ((s[len]) && (len < n))
	{
		newstr[len] = s[len];
		len++;
	}
	newstr[len] = 0;
	return (newstr);
}
