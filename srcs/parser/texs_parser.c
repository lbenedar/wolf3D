/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texs_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:57:40 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 18:36:20 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

static char	dir_parser(t_pars *info, t_path dir, char *line)
{
	while (*line == ' ')
		line++;
	if (*line)
	{
		if (!(line[0] == '.' && line[1] == '/'))
			return (CUB_ERROR);
		if (info->tex->p[dir])
			return (CUB_ERROR);
		if (!(info->tex->p[dir] = ft_strdup(line)))
			return (MEM_ERROR);
		if (is_pars_full(info))
			info->full_base = 1;
		return (NO_ERROR);
	}
	else
		return (CUB_ERROR);
}

char		texs_parser(t_pars *info, char *line)
{
	char result;

	result = CUB_ERROR;
	if ((line[0] == 'N') && (line[1] == 'O'))
		result = dir_parser(info, NO, line + 2);
	else if ((line[0] == 'S') && (line[1] == 'O'))
		result = dir_parser(info, SO, line + 2);
	else if ((line[0] == 'W') && (line[1] == 'E'))
		result = dir_parser(info, WE, line + 2);
	else if ((line[0] == 'E') && (line[1] == 'A'))
		result = dir_parser(info, EA, line + 2);
	else if ((line[0] == 'S') && (line[1] == ' '))
		result = dir_parser(info, S, line + 1);
	free(line);
	return (result);
}
