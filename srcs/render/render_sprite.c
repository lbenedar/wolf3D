/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:57:20 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 23:42:04 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;

static void	set_up_sprite(int i, t_sprite *spr)
{
	spr->x = g_game.w.arr_spr[g_game.w.spr_ord[i]].x + 0.5 - g_game.plr.x;
	spr->y = g_game.w.arr_spr[g_game.w.spr_ord[i]].y + 0.5 - g_game.plr.y;
	spr->inv_det = 1. / (g_game.plr.f_x * g_game.plr.d_y
						- g_game.plr.f_y * g_game.plr.d_x);
	spr->trans_x = spr->inv_det * (g_game.plr.d_y * spr->x
									- g_game.plr.d_x * spr->y);
	spr->trans_y = spr->inv_det * (g_game.plr.f_x * spr->y
									- g_game.plr.f_y * spr->x);
	spr->scr_x = (int)((g_game.w.res.x / 2) *
						(1 + spr->trans_x / spr->trans_y));
	spr->h = abs((int)(g_game.w.res.x * g_game.w.prop_h / spr->trans_y));
	if ((spr->draw_s_y = (-1) * spr->h / 2 + g_game.w.res.y / 2) < 0)
		spr->draw_s_y = 0;
	if ((spr->draw_e_y = spr->h / 2 + g_game.w.res.y / 2) > g_game.w.res.y)
		spr->draw_e_y = g_game.w.res.y;
	spr->w = abs((int)(g_game.w.res.x * g_game.w.prop_h / spr->trans_y));
	if ((spr->draw_s_x = (-1) * spr->w / 2 + spr->scr_x) < 0)
		spr->draw_s_x = 0;
	if ((spr->draw_e_x = spr->w / 2 + spr->scr_x) > g_game.w.res.x)
		spr->draw_e_x = g_game.w.res.x;
}

void		draw_sprite(t_rc *ray, t_sprite *spr,
						t_img_buf *buf_frm, t_img_buf *line)
{
	int	y;
	int	d;

	while (++spr->xline < spr->draw_e_x)
	{
		ray->tex_x = (int)(256 * (spr->xline - (-spr->w / 2 + spr->scr_x))
								* g_game.w.img_w / spr->w) / 256;
		y = spr->draw_s_y - 1;
		if (spr->trans_y > 0 && spr->xline >= 0 && spr->xline < g_game.w.res.x
			&& spr->trans_y < ray->buf_wall_d[spr->xline])
			while (++y < spr->draw_e_y)
			{
				d = y * 256 - g_game.w.res.y * 128 + spr->h * 128;
				ray->tex_y = ((d * g_game.w.img_h) / spr->h) / 256;
				line->pix = ray->tex_y * line->s_l + (ray->tex_x * 4);
				buf_frm->pix = y * buf_frm->s_l + (spr->xline * 4);
				if (!line->buf[line->pix])
					continue ;
				buf_frm->buf[buf_frm->pix] = line->buf[line->pix];
				buf_frm->buf[buf_frm->pix + 1] = line->buf[line->pix + 1];
				buf_frm->buf[buf_frm->pix + 2] = line->buf[line->pix + 2];
				buf_frm->buf[buf_frm->pix + 3] = line->buf[line->pix + 3];
			}
	}
}

void		render_sprite(t_rc *ray, void *frame, t_texs **arr_texs)
{
	int			i;
	t_img_buf	line;
	t_img_buf	buf_frm;
	t_sprite	spr;

	i = -1;
	while (++i < g_game.w.spr_len)
	{
		set_up_sprite(i, &spr);
		g_game.w.img = arr_texs[S]->img;
		g_game.w.img_w = arr_texs[S]->img_w;
		g_game.w.img_h = arr_texs[S]->img_h;
		line.buf = mlx_get_data_addr(g_game.w.img, &line.b_pxl,
									&line.s_l, &line.endian);
		buf_frm.buf = mlx_get_data_addr(frame, &buf_frm.b_pxl,
										&buf_frm.s_l, &buf_frm.endian);
		spr.xline = spr.draw_s_x - 1;
		draw_sprite(ray, &spr, &buf_frm, &line);
	}
}
