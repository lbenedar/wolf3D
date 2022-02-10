/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:56:18 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 23:20:06 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;

static int		cast_ray(t_rc *ray)
{
	int	hit;
	int	side;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dst_x < ray->side_dst_y)
		{
			ray->side_dst_x += ray->delta_x;
			ray->x_crd += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dst_y += ray->delta_y;
			ray->y_crd += ray->step_y;
			side = 1;
		}
		if (g_game.map[ray->y_crd][ray->x_crd] == '1')
			hit = 1;
	}
	return (side);
}

static double	get_wall_dist(t_rc *ray)
{
	ray->delta_x = fabs(1 / ray->rd_x);
	ray->delta_y = fabs(1 / ray->rd_y);
	ray->x_crd = (int)g_game.plr.x;
	ray->y_crd = (int)g_game.plr.y;
	if ((ray->rd_x < 0) && (ray->step_x = -1))
		ray->side_dst_x = (g_game.plr.x - ray->x_crd) * ray->delta_x;
	else if ((ray->step_x = 1))
		ray->side_dst_x = (ray->x_crd + 1. - g_game.plr.x) * ray->delta_x;
	if ((ray->rd_y < 0) && (ray->step_y = -1))
		ray->side_dst_y = (g_game.plr.y - ray->y_crd) * ray->delta_y;
	else if ((ray->step_y = 1))
		ray->side_dst_y = (ray->y_crd + 1. - g_game.plr.y) * ray->delta_y;
	if (!(ray->side = cast_ray(ray)))
	{
		ray->texs_code = ray->step_x > 0 ? EA : WE;
		return ((ray->x_crd - g_game.plr.x +
				(1 - ray->step_x) / 2) / ray->rd_x);
	}
	else
	{
		ray->texs_code = ray->step_y > 0 ? SO : NO;
		return ((ray->y_crd - g_game.plr.y +
				(1 - ray->step_y) / 2) / ray->rd_y);
	}
}

static void		draw_colour(int start, int end, t_img_buf *buf_frm, int x)
{
	int colour;

	if (!start)
		colour = C_colour;
	else
		colour = F_colour;
	if (start < 0)
		start = 0;
	while (start < end)
	{
		buf_frm->pix = start * buf_frm->s_l + (x * 4);
		if (!buf_frm->endian)
		{
			buf_frm->buf[buf_frm->pix + 3] = 0xFF;
			buf_frm->buf[buf_frm->pix + 2] = g_game.w.texs.colour[colour].red;
			buf_frm->buf[buf_frm->pix + 1] = g_game.w.texs.colour[colour].green;
			buf_frm->buf[buf_frm->pix] = g_game.w.texs.colour[colour].blue;
		}
		++start;
	}
}

static void		draw_line(int line_height, t_rc *ray, int x, void *frame)
{
	double		step;
	double		tex_pos;
	t_img_buf	line;
	t_img_buf	buf_frm;

	step = (double)g_game.w.img_h / line_height;
	tex_pos = (ray->draw_pos_s - g_game.w.res.y / 2 + line_height / 2) * step;
	line.buf = mlx_get_data_addr(g_game.w.img, &line.b_pxl,
								&line.s_l, &line.endian);
	buf_frm.buf = mlx_get_data_addr(frame, &buf_frm.b_pxl,
									&buf_frm.s_l, &buf_frm.endian);
	draw_colour(0, ray->draw_pos_s, &buf_frm, x);
	while (ray->draw_pos_s < ray->draw_pos_e)
	{
		ray->tex_y = (int)tex_pos & (g_game.w.img_h - 1);
		tex_pos += step;
		line.pix = ray->tex_y * line.s_l + (ray->tex_x * 4);
		buf_frm.pix = ray->draw_pos_s * buf_frm.s_l + (x * 4);
		buf_frm.buf[buf_frm.pix] = line.buf[line.pix];
		buf_frm.buf[buf_frm.pix + 1] = line.buf[line.pix + 1];
		buf_frm.buf[buf_frm.pix + 2] = line.buf[line.pix + 2];
		buf_frm.buf[buf_frm.pix + 3] = line.buf[line.pix + 3];
		++(ray->draw_pos_s);
	}
	draw_colour(ray->draw_pos_e, g_game.w.res.y, &buf_frm, x);
}

double			render_walls(t_rc *ray, int x, void *frame, t_texs **arr_texs)
{
	double	wall_x;
	double	wall_dst;
	int		line_height;

	wall_dst = get_wall_dist(ray);
	line_height = (int)(g_game.w.res.x * g_game.w.prop_h / wall_dst);
	ray->draw_pos_s = -line_height / 2 + g_game.w.res.y / 2;
	if (ray->draw_pos_s < 0)
		ray->draw_pos_s = 0;
	ray->draw_pos_e = line_height / 2 + g_game.w.res.y / 2;
	if (ray->draw_pos_e > g_game.w.res.y)
		ray->draw_pos_e = g_game.w.res.y;
	if (ray->side)
		wall_x = g_game.plr.x + wall_dst * ray->rd_x;
	else
		wall_x = g_game.plr.y + wall_dst * ray->rd_y;
	wall_x -= floor(wall_x);
	g_game.w.img = arr_texs[ray->texs_code]->img;
	g_game.w.img_w = arr_texs[ray->texs_code]->img_w;
	g_game.w.img_h = arr_texs[ray->texs_code]->img_h;
	ray->tex_x = (int)(wall_x * g_game.w.img_w);
	if ((!ray->side && ray->rd_x > 0) || (ray->side && ray->rd_y < 0))
		ray->tex_x = g_game.w.img_w - ray->tex_x - 1;
	draw_line(line_height, ray, x, frame);
	return (wall_dst);
}
