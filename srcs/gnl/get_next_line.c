/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:14:52 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 20:22:15 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	create_line(char **str, char **linestr)
{
	char *substr;

	if (!(strcat_newline(linestr, *str)))
	{
		free(*str);
		*str = 0;
		if (*linestr)
			free(*linestr);
		linestr = 0;
		return (0);
	}
	if (!(substr = skip_line(*str)))
	{
		free(*str);
		*str = 0;
		if (*linestr)
			free(*linestr);
		linestr = 0;
		return (0);
	}
	free(*str);
	(*str) = substr;
	return (1);
}

static ssize_t	find_create_line(char **str, char **substr,
								char **line, ssize_t line_end)
{
	ssize_t len;

	len = find_end_line(*str);
	if (!create_line(str, substr))
		return (-1);
	if (((*str)[0]) || ((!(*str)[0]) && (len == line_end - 1)))
	{
		*line = *substr;
		return (1);
	}
	free(*str);
	*str = 0;
	return (0);
}

static ssize_t	read_line(char **str, char **substr, int fd, char **line)
{
	ssize_t		r_res;
	ssize_t		result;

	while (((*str) = malloc(BUFFER_SIZE + 1)) &&
			(r_res = read(fd, *str, BUFFER_SIZE)))
	{
		if (r_res == -1)
		{
			free(*str);
			*str = 0;
			return (-1);
		}
		(*str)[r_res] = 0;
		if ((result = find_create_line(str, substr, line, r_res)))
			return (result);
	}
	if (*str)
		free(*str);
	*str = 0;
	return (0);
}

static ssize_t	read_file(char **str, char **substr, int fd, char **line)
{
	ssize_t		result;

	*line = 0;
	result = read_line(str, substr, fd, line);
	if (result)
		return (result);
	if (!(*substr))
	{
		if (!(*substr = malloc(sizeof(char))))
			return (-1);
		**substr = 0;
	}
	*line = *substr;
	return (0);
}

int				get_next_line(int fd, char **line, char **str)
{
	char		*substr;
	size_t		len_line;
	size_t		len;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (line == NULL))
		return (-1);
	substr = 0;
	if (*str)
	{
		len_line = find_end_line(*str);
		len = 0;
		while ((*str)[len])
			len++;
		if (!create_line(str, &substr))
			return (-1);
		if ((!(**str)) && (len_line != len - 1))
		{
			free(*str);
			*str = 0;
		}
		if ((*str) && (*line = substr))
			return (1);
	}
	return (read_file(str, &substr, fd, line));
}
