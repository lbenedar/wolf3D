/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:29:51 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/22 20:59:38 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft.h"
# include "error.h"

typedef struct	s_colour
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_colour;

typedef struct	s_mdir
{
	char	up;
	char	down;
	char	left;
	char	right;
}				t_mdir;

typedef struct	s_point
{
	int	x;
	int y;
}				t_point;

typedef enum	e_path
{
	NO,
	SO,
	WE,
	EA,
	S
}				t_path;

typedef enum	e_key
{
	W_KEY,
	A_KEY,
	S_KEY,
	D_KEY,
	LEFT_KEY,
	RIGHT_KEY,
	ESC_KEY
}				t_key;

typedef enum	e_en_colour
{
	F_colour,
	C_colour
}				t_en_colour;

typedef struct	s_textures
{
	char		*p[5];
	t_colour	colour[2];
}				t_textures;

typedef	struct	s_pars
{
	t_point		*res;
	t_textures	*tex;
	char		full_base;
	char		floor_fill;
	char		ceil_fill;
}				t_pars;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	inv_det;
	double	trans_x;
	double	trans_y;
	int		h;
	int		w;
	int		scr_x;
	int		draw_s_y;
	int		draw_e_y;
	int		draw_s_x;
	int		draw_e_x;
	int		xline;
}				t_sprite;

typedef struct	s_win
{
	double		prop_h;
	double		prop_w;
	void		*mlx;
	void		*win;
	void		*img;
	int			img_w;
	int			img_h;
	t_point		res;
	t_textures	texs;
	t_point		*arr_spr;
	int			*spr_ord;
	int			spr_len;
	char		keys_r[256];
}				t_win;

typedef struct	s_plr
{
	double	x;
	double	y;
	double	d_x;
	double	d_y;
	double	f_x;
	double	f_y;
	double	sp_rot;
	double	sp_mv;
	char	move[7];
}				t_plr;

typedef struct	s_cub
{
	t_win		w;
	t_plr		plr;
	char		**map;
}				t_cub;

typedef struct	s_rc
{
	double	side_dst_x;
	double	side_dst_y;
	double	rd_x;
	double	rd_y;
	double	delta_x;
	double	delta_y;
	double	*buf_wall_d;
	int		tex_x;
	int		tex_y;
	int		draw_pos_s;
	int		draw_pos_e;
	int		step_x;
	int		step_y;
	int		side;
	int		x_crd;
	int		y_crd;
	t_path	texs_code;
}				t_rc;

typedef struct	s_img_buf
{
	char	*buf;
	int		b_pxl;
	int		s_l;
	int		endian;
	int		pix;
}				t_img_buf;

typedef struct	s_texs
{
	void	*img;
	int		img_w;
	int		img_h;
}				t_texs;

typedef struct	s_plr_map
{
	char	**label;
	int		*lines_len;
}				t_plr_map;

# pragma pack(push, 1)

typedef struct	s_bmp_h
{
	unsigned short	b_type;
	unsigned int	b_size;
	unsigned short	b_reserv_1;
	unsigned short	b_reserv_2;
	unsigned int	b_off_bits;
}				t_bmp_h;

typedef struct	s_bmp_i
{
	unsigned int	b_size;
	int				b_width;
	int				b_height;
	unsigned short	b_planes;
	unsigned short	b_bit_count;
	unsigned int	b_compress;
	unsigned int	b_size_image;
	int				b_x_pels;
	int				b_y_pels;
	unsigned int	b_clr_used;
	unsigned int	b_clr_imp;
}				t_bmp_i;

# pragma pack(pop)

char			is_pars_full(t_pars *info);
void			ft_init_pars(t_pars *info);
void			ft_out_pars(t_pars *info);

#endif
