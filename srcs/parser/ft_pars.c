/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:53:41 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/14 19:22:43 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

extern	t_cub	g_game;

char			is_pars_full(t_pars *info)
{
	if (((!info->res->x) && (!info->res->y)) || !info->tex->p[NO] ||
	!info->tex->p[SO] || !info->tex->p[WE] ||
	!info->tex->p[EA] || !info->tex->p[S] || !info->floor_fill ||
	!info->ceil_fill)
		return (0);
	return (1);
}

void			ft_init_pars(t_pars *info)
{
	info->full_base = 0;
	info->res = &(g_game.w.res);
	info->tex = &(g_game.w.texs);
	info->floor_fill = 0;
	info->ceil_fill = 0;
}
