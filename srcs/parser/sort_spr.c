/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:59:21 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 23:24:39 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;

void			sort_order(double *spr_dst, int *spr_ord, int len)
{
	int i;
	int j;
	int temp;

	i = -1;
	while (++i < len)
	{
		temp = spr_ord[i];
		j = i;
		while (j > 0 && spr_dst[spr_ord[j - 1]] < spr_dst[temp])
		{
			spr_ord[j] = spr_ord[j - 1];
			--j;
		}
		spr_ord[j] = temp;
	}
}

int				*sort_sprites(int len)
{
	int		i;
	double	*spr_dst;
	int		*spr_ord;

	if (!(spr_dst = malloc(sizeof(double) * (len + 1))))
		return (0);
	spr_dst[len] = 0;
	if (!(spr_ord = malloc(sizeof(int) * (len + 1))))
	{
		free(spr_dst);
		return (0);
	}
	spr_ord[len] = 0;
	i = -1;
	while (++i < len)
	{
		spr_dst[i] = (g_game.plr.x - (g_game.w.arr_spr[i].x + 0.5)) *
			(g_game.plr.x - (g_game.w.arr_spr[i].x + 0.5)) +
			(g_game.plr.y - (g_game.w.arr_spr[i].y + 0.5)) *
			(g_game.plr.y - (g_game.w.arr_spr[i].y + 0.5));
		spr_ord[i] = i;
	}
	sort_order(spr_dst, spr_ord, len);
	free(spr_dst);
	return (spr_ord);
}

void			resort_sprites(void)
{
	double	*spr_dst;
	int		len;
	int		i;

	len = g_game.w.spr_len;
	if (!(spr_dst = malloc(sizeof(double) * (len + 1))))
		return ;
	spr_dst[len] = 0;
	i = -1;
	while (++i < len)
	{
		spr_dst[i] = (g_game.plr.x - (g_game.w.arr_spr[i].x + 0.5)) *
			(g_game.plr.x - (g_game.w.arr_spr[i].x + 0.5)) +
			(g_game.plr.y - (g_game.w.arr_spr[i].y + 0.5)) *
			(g_game.plr.y - (g_game.w.arr_spr[i].y + 0.5));
	}
	sort_order(spr_dst, g_game.w.spr_ord, len);
	free(spr_dst);
}
