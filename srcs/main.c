/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:21:19 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/15 18:55:47 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_errors	g_ecode;
extern t_cub	g_game;

static char		check_cub_file(char *path)
{
	int i;

	i = 0;
	while (path[i])
		++i;
	if (path[--i] != 'b')
		return (ARG_ERROR);
	if (path[--i] != 'u')
		return (ARG_ERROR);
	if (path[--i] != 'c')
		return (ARG_ERROR);
	if (path[--i] != '.')
		return (ARG_ERROR);
	return (NO_ERROR);
}

int				main(int argc, char **argv)
{
	g_ecode = 0;
	if (argc > 2)
		if (argc > 3 || ft_strncmp("--save", argv[2], 7))
			exit(out_err_arg(ARG_ERROR));
	if (argc == 1)
		exit(out_err_arg(ARG_ERROR));
	set_cub();
	if (!check_cub_file(argv[1]))
		ft_parse_cub(argv[1]);
	else
		exit(out_err_arg(ARG_ERROR));
	if (g_ecode)
	{
		clear_cub();
		exit(out_error());
	}
	if (argc == 2)
		run_game();
	else
		make_bmp();
	return (0);
}
