/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:39:55 by lbenedar          #+#    #+#             */
/*   Updated: 2020/10/29 18:43:00 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		subn;
	char	subc;
	int		lennum;
	int		neg;

	subn = n;
	lennum = 1;
	neg = 1;
	if (subn < 0)
	{
		write(fd, "-", 1);
		neg = -1;
	}
	while ((subn > 9) || (subn < -9))
	{
		subn /= 10;
		lennum *= 10;
	}
	while (lennum > 0)
	{
		subc = (n / lennum) * neg + 48;
		write(fd, &subc, 1);
		n = n % lennum;
		lennum /= 10;
	}
}
