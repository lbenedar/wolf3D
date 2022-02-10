/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:25:51 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/17 13:28:34 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	if ((!s) || (!f))
		return (0);
	i = 0;
	while (s[i])
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (s[i])
	{
		newstr[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
