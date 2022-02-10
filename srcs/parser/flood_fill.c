/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:45:54 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/16 20:22:57 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_cub.h"

extern t_cub	g_game;

static t_point	*set_point(int i, int j)
{
	t_point *temp_point;

	if (!(temp_point = malloc(sizeof(t_point))))
		return (0);
	temp_point->x = j;
	temp_point->y = i;
	return (temp_point);
}

static char		check_borders(t_plr_map *check, t_point *point)
{
	if (check->label[point->y][point->x])
		return (0);
	check->label[point->y][point->x] = 1;
	if (g_game.map[point->y][point->x] == '1')
		return (0);
	return (1);
}

static char		flood_fill_do(t_plr_map *check, t_point *p, t_list **queue)
{
	if (p->y < 0 || p->x < 0 || (check->lines_len[p->y] < (p->x + 1))
	|| !g_game.map[p->y] || !g_game.map[p->y][p->x]
	|| g_game.map[p->y][p->x] == ' ')
		return (MAP_ERROR);
	if (check_borders(check, p))
	{
		ft_lstadd_front(queue, ft_lstnew(set_point(p->y, p->x - 1)));
		ft_lstadd_front(queue, ft_lstnew(set_point(p->y - 1, p->x)));
		ft_lstadd_front(queue, ft_lstnew(set_point(p->y, p->x + 1)));
		ft_lstadd_front(queue, ft_lstnew(set_point(p->y + 1, p->x)));
	}
	return (NO_ERROR);
}

char			flood_fill(t_plr_map *check, int i, int j)
{
	t_list	*queue;
	t_point *p;
	t_list	*temp_queue;

	if (!(p = set_point(i, j)))
		return (MEM_ERROR);
	queue = 0;
	ft_lstadd_back(&queue, ft_lstnew(p));
	if (!queue)
		return (MEM_ERROR);
	while (queue)
	{
		p = queue->content;
		temp_queue = queue;
		queue = queue->next;
		if (flood_fill_do(check, p, &queue))
			return (MAP_ERROR);
		ft_lstdelone(temp_queue, free);
	}
	return (NO_ERROR);
}
