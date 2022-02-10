/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:08:28 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 18:58:46 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

static	char	*skip_num(char *line)
{
	while (*line == ' ')
		line++;
	if (*line == '+')
		line++;
	while ((*line >= '0') && (*line <= '9'))
		line++;
	return (line);
}

static	char	free_return(char *line)
{
	free(line);
	return (CUB_ERROR);
}

char			res_parser(t_pars *info, char *line)
{
	char *temp_line;

	temp_line = line + 1;
	if (info->res->x)
		return (free_return(line));
	if ((info->res->x = ft_atoi(temp_line)) <= 0)
		return (free_return(line));
	temp_line = skip_num(temp_line);
	if ((info->res->y = ft_atoi(temp_line)) <= 0)
		return (free_return(line));
	temp_line = skip_num(temp_line);
	if (*temp_line)
		return (free_return(line));
	if (is_pars_full(info))
		info->full_base = 1;
	free(line);
	return (NO_ERROR);
}
