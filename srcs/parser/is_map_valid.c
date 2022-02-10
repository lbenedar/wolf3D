/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:58:44 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/15 19:20:26 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

extern	t_cub	g_game;

static char		is_valid_chars(char **map)
{
	int		i;
	int		j;
	char	cm;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			cm = map[i][j];
			if (cm == '0' || cm == '1' || cm == '2' || cm == ' ')
				continue ;
			else if (g_game.plr.x >= 0.)
				return (MAP_ERROR);
			else if (cm == 'N' || cm == 'S' || cm == 'E' || cm == 'W')
			{
				g_game.plr.x = j;
				g_game.plr.y = i;
				continue ;
			}
			return (MAP_ERROR);
		}
	}
	return (NO_ERROR);
}

void			set_up_plr(void)
{
	if (g_game.map[(int)g_game.plr.y][(int)g_game.plr.x] == 'N')
	{
		g_game.plr.d_x = 0;
		g_game.plr.d_y = -1;
		g_game.plr.f_x = FOV;
	}
	else if (g_game.map[(int)g_game.plr.y][(int)g_game.plr.x] == 'S')
	{
		g_game.plr.d_x = 0;
		g_game.plr.d_y = 1;
		g_game.plr.f_x = (-1) * FOV;
	}
	else if (g_game.map[(int)g_game.plr.y][(int)g_game.plr.x] == 'E')
	{
		g_game.plr.d_x = 1;
		g_game.plr.d_y = 0;
		g_game.plr.f_y = FOV;
	}
	else if (g_game.map[(int)g_game.plr.y][(int)g_game.plr.x] == 'W')
	{
		g_game.plr.d_x = -1;
		g_game.plr.d_y = 0;
		g_game.plr.f_y = (-1) * FOV;
	}
}

char			is_map_valid(void)
{
	t_errors error;

	if (!g_game.map)
		return (MAP_ERROR);
	if ((error = is_valid_chars(g_game.map)))
		return (error);
	if (g_game.plr.x < 0)
		return (MAP_ERROR);
	if ((error = is_plr_inside()))
		return (error);
	set_up_plr();
	g_game.plr.x += 0.5;
	g_game.plr.y += 0.5;
	return (NO_ERROR);
}
