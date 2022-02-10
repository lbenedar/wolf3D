/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:05:04 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 20:21:37 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

extern	t_cub		g_game;
extern	t_errors	g_ecode;

static	char		parse_line(t_pars *info, const char *line)
{
	char *sline;

	if (!(sline = ft_strtrim(line, " ")))
		return (MEM_ERROR);
	if (sline[0] == '\0')
	{
		free(sline);
		return (NO_ERROR);
	}
	if (sline[0] == 'R')
		return (res_parser(info, sline));
	else if (sline[0] == 'F' || sline[0] == 'C')
		return (colour_parser(info, sline));
	else if ((sline[0] == 'N' && sline[1] == 'O') ||
			(sline[0] == 'S' && sline[1] == 'O') ||
			(sline[0] == 'W' && sline[1] == 'E') ||
			(sline[0] == 'E' && sline[1] == 'A') ||
			(sline[0] == 'S' && sline[1] == ' '))
		return (texs_parser(info, sline));
	free(sline);
	return (CUB_ERROR);
}

static	void		free_gnl(char *line, char *stat_var)
{
	if (line)
		free(line);
	if (stat_var)
		free(stat_var);
}

static	void		parse_file(t_pars *info_pars, int fd)
{
	char	*line;
	int		res;
	char	*stat_var;

	stat_var = 0;
	while ((res = get_next_line(fd, &line, &stat_var)))
	{
		if (res == -1)
			return ((void)(g_ecode = GNL_ERROR));
		if (info_pars->full_base && (g_ecode = map_parser(line)))
			return (free_gnl(line, stat_var));
		else if (!info_pars->full_base
				&& (g_ecode = parse_line(info_pars, line)))
			return (free_gnl(line, stat_var));
		free(line);
	}
	if ((g_ecode = map_parser(line)))
		return (free(line));
	free(line);
}

void				ft_parse_cub(char *cub_path)
{
	int			fd;
	t_pars		info_pars;

	ft_init_pars(&info_pars);
	if ((fd = open(cub_path, O_RDONLY)) == -1)
		return ((void)(g_ecode = OPEN_ERROR));
	parse_file(&info_pars, fd);
	close(fd);
	if (g_ecode)
		return ;
	return ((void)(g_ecode = is_map_valid()));
}
