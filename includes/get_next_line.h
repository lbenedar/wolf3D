/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:15:28 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 20:21:41 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

int		get_next_line(int fd, char **line, char **str);
size_t	find_end_line(const char *str);
char	*ft_strdup_line(const char *s);
char	*skip_line(char *s);
char	*strcat_newline(char **dst, const char *src);
size_t	ft_strcpy(char *dst, const char *src, size_t len);

#endif
