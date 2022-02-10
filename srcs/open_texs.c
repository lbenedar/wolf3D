/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:59:05 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/15 03:03:21 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_errors	g_ecode;
extern t_cub	g_game;

void			clear_all_texs(t_texs **arr_texs)
{
	int i;

	if (!arr_texs)
		return ;
	i = -1;
	while (++i < 5 && arr_texs[i])
	{
		if (arr_texs[i]->img)
			mlx_destroy_image(g_game.w.mlx, arr_texs[i]->img);
		free(arr_texs[i]);
	}
	free(arr_texs);
	g_game.w.img = 0;
}

static char		open_one_tex(int i, t_texs **arr_texs)
{
	t_texs	*tex;

	if (!(tex = malloc(sizeof(t_texs))))
	{
		clear_all_texs(arr_texs);
		return (g_ecode = MEM_ERROR);
	}
	if (!(tex->img = mlx_xpm_file_to_image(g_game.w.mlx,
		g_game.w.texs.p[i], &tex->img_w, &tex->img_h)))
	{
		clear_all_texs(arr_texs);
		return (g_ecode = PATH_ERROR);
	}
	arr_texs[i] = tex;
	return (NO_ERROR);
}

t_texs			**open_all_texs(void)
{
	t_texs	**arr_texs;
	int		i;

	if (!(arr_texs = malloc(sizeof(t_texs*) * (5))))
	{
		g_ecode = MEM_ERROR;
		return (0);
	}
	i = -1;
	while (++i < 5)
		if (open_one_tex(i, arr_texs))
			return (0);
	return (arr_texs);
}
