/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_spr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:01:28 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/14 18:50:47 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;

int				count_sprites(char **label)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (g_game.map[++i])
	{
		j = -1;
		while (g_game.map[i][++j])
			if (g_game.map[i][j] == '2' && label[i][j])
				++count;
	}
	return (count);
}

void			insert_sprites(char **label)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (g_game.map[++i])
	{
		j = -1;
		while (g_game.map[i][++j])
			if (g_game.map[i][j] == '2' && label[i][j])
			{
				g_game.w.arr_spr[k].x = j;
				g_game.w.arr_spr[k].y = i;
				++k;
			}
	}
}

char			set_up_sprites(char **label)
{
	int count;

	count = count_sprites(label);
	if (!(g_game.w.arr_spr = malloc(sizeof(t_sprite) * (count + 1))))
		return (MEM_ERROR);
	insert_sprites(label);
	g_game.w.spr_len = count;
	if (!(g_game.w.spr_ord = sort_sprites(count)))
	{
		free(g_game.w.arr_spr);
		g_game.w.arr_spr = 0;
		return (MEM_ERROR);
	}
	return (NO_ERROR);
}
