/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:08:20 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/15 17:15:14 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

t_errors		g_ecode;

static char		*get_error(void)
{
	if (g_ecode == OPEN_ERROR)
		return ("Error\nFile can not be opened\n");
	if (g_ecode == PARSE_ERROR)
		return ("Error\nFile can not be parsed\n");
	if (g_ecode == GNL_ERROR)
		return ("Error\nGNL can not read line\n");
	if (g_ecode == MEM_ERROR)
		return ("Error\nMemory can not be malloced\n");
	if (g_ecode == MAP_ERROR)
		return ("Error\nMap can not be parsed\n");
	if (g_ecode == CUB_ERROR)
		return ("Error\nFile can not be parsed\n");
	if (g_ecode == CUB_ERROR)
		return ("Error\nProblem with arguments\n");
	if (g_ecode == TODO_ERROR)
		return ("Error\nThis error has not been implemented\n");
	if (g_ecode == SPRITE_ERROR)
		return ("Error\nProblem in sprite set up\n");
	if (g_ecode == PATH_ERROR)
		return ("Error\nProblem with texs path\n");
	if (g_ecode == MLX_ERROR)
		return ("Error\nProblem with mlx lib\n");
	if (g_ecode == ARG_ERROR)
		return ("Error\nProblem with arguments\n");
	return ("No Error\n");
}

t_errors		out_error(void)
{
	ft_putstr_fd("\033[38;5;160m", 2);
	ft_putstr_fd(get_error(), 2);
	ft_putstr_fd("\033[30;0m", 2);
	return (g_ecode);
}

t_errors		out_err_arg(t_errors err)
{
	g_ecode = err;
	ft_putstr_fd("\033[38;5;160m", 2);
	ft_putstr_fd(get_error(), 2);
	ft_putstr_fd("\033[30;0m", 2);
	return (g_ecode);
}
