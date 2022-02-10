/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:06:49 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/14 22:40:33 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;

void			move_plr_ud(void)
{
	double new_x;
	double new_y;

	new_x = g_game.plr.d_x * g_game.plr.sp_mv;
	new_y = g_game.plr.d_y * g_game.plr.sp_mv;
	if (g_game.plr.move[W_KEY])
	{
		if (g_game.map[(int)g_game.plr.y][(int)(g_game.plr.x + new_x)] == '0')
			g_game.plr.x += new_x;
		if (g_game.map[(int)(g_game.plr.y + new_y)][(int)g_game.plr.x] == '0')
			g_game.plr.y += new_y;
	}
	else if (g_game.plr.move[S_KEY])
	{
		if (g_game.map[(int)g_game.plr.y][(int)(g_game.plr.x - new_x)] == '0')
			g_game.plr.x -= new_x;
		if (g_game.map[(int)(g_game.plr.y - new_y)][(int)g_game.plr.x] == '0')
			g_game.plr.y -= new_y;
	}
}

void			move_plr_lr(void)
{
	double new_x;
	double new_y;

	new_x = (g_game.plr.d_y * (-1)) * g_game.plr.sp_mv;
	new_y = (g_game.plr.d_x) * g_game.plr.sp_mv;
	if (g_game.plr.move[A_KEY])
	{
		if (g_game.map[(int)g_game.plr.y][(int)(g_game.plr.x + new_x)] == '0')
			g_game.plr.x += new_x;
		if (g_game.map[(int)(g_game.plr.y + new_y)][(int)g_game.plr.x] == '0')
			g_game.plr.y += new_y;
	}
	else if (g_game.plr.move[D_KEY])
	{
		if (g_game.map[(int)g_game.plr.y][(int)(g_game.plr.x - new_x)] == '0')
			g_game.plr.x -= new_x;
		if (g_game.map[(int)(g_game.plr.y - new_y)][(int)g_game.plr.x] == '0')
			g_game.plr.y -= new_y;
	}
}

void			turn_around(void)
{
	double	old_dirx;
	double	old_fovx;
	double	sp;

	old_dirx = g_game.plr.d_x;
	old_fovx = g_game.plr.f_x;
	sp = g_game.plr.sp_rot;
	if (g_game.plr.move[RIGHT_KEY])
		sp *= (-1);
	g_game.plr.d_x = g_game.plr.d_x * cos(sp) - g_game.plr.d_y * sin(sp);
	g_game.plr.d_y = old_dirx * sin(sp) + g_game.plr.d_y * cos(sp);
	g_game.plr.f_x = g_game.plr.f_x * cos(sp) - g_game.plr.f_y * sin(sp);
	g_game.plr.f_y = old_fovx * sin(sp) + g_game.plr.f_y * cos(sp);
}
