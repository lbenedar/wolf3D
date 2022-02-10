/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:19:24 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/14 19:06:53 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

extern	t_cub	g_game;

static	size_t	ft_count_line(char **map)
{
	size_t i;

	i = 0;
	if (!map)
		return (i);
	while (map[i])
		++i;
	return (i);
}

char			map_parser(char *line)
{
	char	**map;
	size_t	i;

	if (!(*line) && !g_game.map)
		return (NO_ERROR);
	else if (!(*line) && g_game.map)
		return (MAP_ERROR);
	map = g_game.map;
	if (!(g_game.map = malloc(sizeof(char*) * (ft_count_line(map) + 2))))
	{
		if (map)
			clear_map();
		return (MEM_ERROR);
	}
	i = 0;
	if ((map) && (i = -1))
	{
		while (map[++i])
			g_game.map[i] = map[i];
		free(map);
	}
	g_game.map[i] = ft_strdup(line);
	g_game.map[++i] = 0;
	return (NO_ERROR);
}
