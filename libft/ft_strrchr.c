/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:31:28 by lbenedar          #+#    #+#             */
/*   Updated: 2020/11/06 11:31:55 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	*subs;
	int		i;
	int		j;

	last = (char*)s;
	subs = (char*)s;
	i = 0;
	j = -1;
	while (subs[i])
	{
		if (subs[i] == c)
		{
			j = i;
			last = (subs + j);
		}
		i++;
	}
	if (subs[i] == c)
		return (subs + i);
	if (j != -1)
		return (last);
	return (0);
}
