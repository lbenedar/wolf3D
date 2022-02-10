/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:03:04 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/14 23:18:08 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_cub		g_game;

void		clear_map(char **map)
{
	size_t i;

	if (!map)
		return ;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void		out_map(void)
{
	int i;

	i = -1;
	while (g_game.map[++i])
	{
		ft_putstr_fd(g_game.map[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

static void	set_controls(void)
{
	int i;

	i = -1;
	while (++i < 7)
		g_game.plr.move[i] = 0;
}

void		set_cub(void)
{
	g_game.plr.x = -1.;
	g_game.plr.y = -1.;
	g_game.plr.d_x = -1.;
	g_game.plr.d_y = -1.;
	g_game.plr.f_x = 0.;
	g_game.plr.f_y = 0.;
	g_game.map = 0;
	g_game.w.res.x = 0;
	g_game.w.res.y = 0;
	g_game.w.texs.p[NO] = 0;
	g_game.w.texs.p[SO] = 0;
	g_game.w.texs.p[WE] = 0;
	g_game.w.texs.p[EA] = 0;
	g_game.w.texs.p[S] = 0;
	g_game.w.mlx = 0;
	g_game.w.win = 0;
	g_game.w.img = 0;
	g_game.w.arr_spr = 0;
	g_game.w.spr_ord = 0;
	set_controls();
}

void		clear_cub(void)
{
	clear_map(g_game.map);
	if (g_game.w.texs.p[NO])
		free(g_game.w.texs.p[NO]);
	if (g_game.w.texs.p[SO])
		free(g_game.w.texs.p[SO]);
	if (g_game.w.texs.p[WE])
		free(g_game.w.texs.p[WE]);
	if (g_game.w.texs.p[EA])
		free(g_game.w.texs.p[EA]);
	if (g_game.w.texs.p[S])
		free(g_game.w.texs.p[S]);
	if (g_game.w.arr_spr)
		free(g_game.w.arr_spr);
	if (g_game.w.spr_ord)
		free(g_game.w.spr_ord);
	set_cub();
}
