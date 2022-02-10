/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:27:03 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 18:59:46 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

static void	set_info_colour(t_pars *info, t_en_colour surface)
{
	if (surface == F_colour)
		info->floor_fill = 1;
	else
		info->ceil_fill = 1;
}

static char	parse_colour(t_pars *info, t_en_colour surface, const char *line)
{
	while (*line == ' ')
		line++;
	if (*line < '0' || *line > '9')
		return (CUB_ERROR);
	info->tex->colour[surface].red = ft_uatoi(line);
	while ((*line >= '0') && (*line <= '9'))
		line++;
	if (line[0] != ',' || line[1] < '0' || line[1] > '9')
		return (CUB_ERROR);
	info->tex->colour[surface].green = ft_uatoi(++line);
	while ((*line >= '0') && (*line <= '9'))
		line++;
	if (line[0] != ',' || line[1] < '0' || line[1] > '9')
		return (CUB_ERROR);
	info->tex->colour[surface].blue = ft_uatoi(++line);
	while ((*line >= '0') && (*line <= '9'))
		line++;
	if (line[0])
		return (CUB_ERROR);
	set_info_colour(info, surface);
	if (is_pars_full(info))
		info->full_base = 1;
	return (NO_ERROR);
}

char		colour_parser(t_pars *info, char *line)
{
	char result;

	result = CUB_ERROR;
	if (*line == 'F')
	{
		if (!info->floor_fill)
			result = parse_colour(info, F_colour, line + 1);
	}
	else if (*line == 'C')
		if (!info->ceil_fill)
			result = parse_colour(info, C_colour, line + 1);
	free(line);
	return (result);
}
