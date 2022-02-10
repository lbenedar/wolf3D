/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 00:20:29 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 22:12:53 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;
extern t_errors	g_ecode;

static int	key_pressed(int keycode, t_plr *plr)
{
	if (keycode == 119)
		plr->move[W_KEY] = 1;
	if (keycode == 115)
		plr->move[S_KEY] = 1;
	if (keycode == 97)
		plr->move[D_KEY] = 1;
	if (keycode == 100)
		plr->move[A_KEY] = 1;
	if (keycode == 65361)
		plr->move[RIGHT_KEY] = 1;
	if (keycode == 65363)
		plr->move[LEFT_KEY] = 1;
	if (keycode == 65307)
		plr->move[ESC_KEY] = 1;
	return (1);
}

static int	key_released(int keycode, t_plr *plr)
{
	if (keycode == 119)
		plr->move[W_KEY] = 0;
	if (keycode == 115)
		plr->move[S_KEY] = 0;
	if (keycode == 97)
		plr->move[D_KEY] = 0;
	if (keycode == 100)
		plr->move[A_KEY] = 0;
	if (keycode == 65361)
		plr->move[RIGHT_KEY] = 0;
	if (keycode == 65363)
		plr->move[LEFT_KEY] = 0;
	return (1);
}

static int	destroy_all(t_texs **arr_texs)
{
	clear_all_texs(arr_texs);
	mlx_destroy_window(g_game.w.mlx, g_game.w.win);
	mlx_destroy_display(g_game.w.mlx);
	free(g_game.w.mlx);
	clear_cub();
	exit(0);
	return (0);
}

void		check_res_size(void)
{
	int weight;
	int height;

	mlx_get_screen_size(g_game.w.mlx, &weight, &height);
	if (g_game.w.res.x > weight)
		g_game.w.res.x = weight;
	if (g_game.w.res.y > height)
		g_game.w.res.y = height;
	g_game.plr.sp_mv = SPEED * g_game.w.res.x * g_game.w.res.y / 10000;
	g_game.plr.sp_rot = R_SPEED * g_game.w.res.x * g_game.w.res.y / 10000;
	g_game.w.prop_w = 1;
	g_game.w.prop_h = (double)height / weight;
}

void		run_game(void)
{
	t_texs	**arr_texs;

	g_game.w.mlx = mlx_init();
	g_game.map[(int)g_game.plr.y][(int)g_game.plr.x] = '0';
	check_res_size();
	if (!(arr_texs = open_all_texs()))
	{
		mlx_destroy_display(g_game.w.mlx);
		free(g_game.w.mlx);
		clear_cub();
		exit(out_error());
	}
	g_game.w.win = mlx_new_window(g_game.w.mlx,
		g_game.w.res.x, g_game.w.res.y, "cub3D");
	mlx_hook(g_game.w.win, 2, 1L << 0, key_pressed, &g_game.plr);
	mlx_hook(g_game.w.win, 3, 1L << 1, key_released, &g_game.plr);
	mlx_hook(g_game.w.win, 33, 0L, destroy_all, arr_texs);
	mlx_loop_hook(g_game.w.mlx, render_frame, arr_texs);
	mlx_loop(g_game.w.mlx);
}
