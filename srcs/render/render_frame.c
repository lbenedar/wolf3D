/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:04:23 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 23:21:44 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;

char			render(void *frame, t_texs **arr_texs)
{
	int		x;
	t_rc	ray;
	double	sr_x;
	double	sr_y;

	x = -1;
	sr_x = g_game.plr.d_x;
	sr_y = g_game.plr.d_y;
	if (!(ray.buf_wall_d = malloc(sizeof(double) * g_game.w.res.x)))
		return (MEM_ERROR);
	while (++x < g_game.w.res.x)
	{
		ray.rd_x = sr_x + g_game.plr.f_x * (2 * (double)x / g_game.w.res.x - 1);
		ray.rd_y = sr_y + g_game.plr.f_y * (2 * (double)x / g_game.w.res.x - 1);
		ray.buf_wall_d[x] = render_walls(&ray, x, frame, arr_texs);
	}
	render_sprite(&ray, frame, arr_texs);
	free(ray.buf_wall_d);
	return (NO_ERROR);
}

static int		do_plr_action(t_texs **arr_texs)
{
	if (g_game.plr.move[W_KEY] || g_game.plr.move[S_KEY]
		|| g_game.plr.move[D_KEY] || g_game.plr.move[A_KEY])
	{
		move_plr_ud();
		move_plr_lr();
		resort_sprites();
	}
	if (g_game.plr.move[LEFT_KEY] || g_game.plr.move[RIGHT_KEY])
		turn_around();
	if (g_game.plr.move[ESC_KEY])
	{
		clear_all_texs(arr_texs);
		mlx_destroy_window(g_game.w.mlx, g_game.w.win);
		mlx_destroy_display(g_game.w.mlx);
		free(g_game.w.mlx);
		clear_cub();
		exit(0);
	}
	return (1);
}

int				render_frame(void *arr_texs)
{
	void *frame;

	frame = mlx_new_image(g_game.w.mlx, g_game.w.res.x, g_game.w.res.y);
	if (render(frame, (t_texs**)arr_texs))
	{
		clear_all_texs((t_texs**)arr_texs);
		mlx_destroy_window(g_game.w.mlx, g_game.w.win);
		mlx_destroy_display(g_game.w.mlx);
		free(g_game.w.mlx);
		clear_cub();
		exit(out_err_arg(MEM_ERROR));
	}
	mlx_put_image_to_window(g_game.w.mlx, g_game.w.win, frame, 0, 0);
	mlx_destroy_image(g_game.w.mlx, frame);
	do_plr_action((t_texs**)arr_texs);
	return (1);
}
