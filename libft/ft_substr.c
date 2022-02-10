/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:51:15 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/01 01:43:28 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t last;

	if (!s)
		return (0);
	last = ft_strlen(s);
	if (start < last)
		return (ft_strndup(s + start, len));
	else
		return (ft_strndup(s + last, len));
}
