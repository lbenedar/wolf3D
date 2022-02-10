/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:28:25 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/16 16:00:50 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_CUB_H
# define FT_PARSE_CUB_H

# include "types.h"
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "cub3d.h"
# include "math.h"

char			res_parser(t_pars *info, char *line);
char			colour_parser(t_pars *info, char *line);
char			texs_parser(t_pars *info, char *line);
char			build_map(t_list **map);
char			map_parser(char *line);
void			ft_parse_cub(char *cub_path);
char			is_map_valid(void);
char			is_plr_inside(void);
char			set_up_sprites(char **label);
int				*sort_sprites(int len);
char			flood_fill(t_plr_map *check, int i, int j);

#endif
