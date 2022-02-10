/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:26:18 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 23:42:49 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "types.h"
# include "ft_parse_cub.h"
# include "mlx.h"
# include <math.h>
# define SPEED 0.0003
# define FLOOR 0.5
# define DIR_STEP 32
# define PI 3.14159
# define R_SPEED 0.0002
# define FOV (PI / 3)
# define BITCOUNT 24

void	run_game(void);
void	clear_cub(void);
void	clear_map(void);
void	out_map(void);
void	set_cub(void);
char	render(void *frame, t_texs **arr_texs);
int		render_frame(void *str);
double	render_walls(t_rc *ray, int x, void *frame, t_texs **arr_texs);
void	render_sprite(t_rc *ray, void *frame, t_texs **arr_texs);
void	resort_sprites(void);
void	init_game(void);
void	turn_around(void);
void	move_plr_lr(void);
void	move_plr_ud(void);
t_texs	**open_all_texs(void);
void	clear_all_texs(t_texs **arr_texs);
void	make_bmp(void);
void	check_res_size(void);

#endif
