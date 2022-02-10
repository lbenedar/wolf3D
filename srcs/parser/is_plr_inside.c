/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_plr_inside.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:14:48 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/16 15:49:23 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

extern t_cub	g_game;

static char		**fill_label_map(void)
{
	char	**label;
	int		i;
	int		j;

	i = 0;
	while (g_game.map[i])
		++i;
	if (!(label = malloc(sizeof(char*) * (i + 1))))
		return (0);
	label[i] = 0;
	i = -1;
	while (g_game.map[++i])
	{
		j = 0;
		while (g_game.map[i][j])
			++j;
		if (!(label[i] = ft_calloc(sizeof(char), (j + 1))))
		{
			while (--i > 0)
				free(label[i]);
			free(label);
			return (0);
		}
	}
	return (label);
}

static void		clear_label_map(char **label)
{
	size_t i;

	i = -1;
	while (g_game.map[++i])
		free(label[i]);
	free(label);
}

static char		fill_lines_len(int **lines_len)
{
	int i;

	i = 0;
	while (g_game.map[i])
		++i;
	if (!(*lines_len = malloc(sizeof(int) * (i + 1))))
		return (MEM_ERROR);
	i = -1;
	while (g_game.map[++i])
		(*lines_len)[i] = (int)ft_strlen(g_game.map[i]);
	(*lines_len)[i] = 0;
	return (NO_ERROR);
}

char			is_plr_inside(void)
{
	t_plr_map check;

	if (!(check.label = fill_label_map()))
		return (MEM_ERROR);
	check.lines_len = 0;
	if (fill_lines_len(&check.lines_len))
	{
		clear_label_map(check.label);
		return (MEM_ERROR);
	}
	if (flood_fill(&check, g_game.plr.y, g_game.plr.x))
	{
		clear_label_map(check.label);
		free(check.lines_len);
		return (MAP_ERROR);
	}
	if (set_up_sprites(check.label))
		return (SPRITE_ERROR);
	clear_label_map(check.label);
	free(check.lines_len);
	return (NO_ERROR);
}
