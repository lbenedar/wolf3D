/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:04:18 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/19 20:27:51 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_cub	g_game;
extern t_errors	g_ecode;

static void				*take_frame(void)
{
	t_texs	**arr_texs;
	void	*frame;

	g_game.map[(int)g_game.plr.y][(int)g_game.plr.x] = '0';
	check_res_size();
	if (!(arr_texs = open_all_texs()))
	{
		mlx_destroy_display(g_game.w.mlx);
		free(g_game.w.mlx);
		clear_cub();
		exit(out_error());
	}
	frame = mlx_new_image(g_game.w.mlx, g_game.w.res.x, g_game.w.res.y);
	render(frame, arr_texs);
	clear_all_texs(arr_texs);
	return (frame);
}

static unsigned char	*write_pxl_data(unsigned int img_size,
								unsigned int w_bytes, void *frame)
{
	unsigned char	*buf;
	unsigned int	index;
	int				i;
	int				j;
	t_img_buf		buf_frm;

	i = g_game.w.res.y;
	buf_frm.buf = mlx_get_data_addr(frame, &buf_frm.b_pxl,
									&buf_frm.s_l, &buf_frm.endian);
	if (!(buf = malloc(sizeof(unsigned char) * img_size)))
		return (0);
	while (--i >= 0)
	{
		j = -1;
		while (++j < g_game.w.res.x)
		{
			buf_frm.pix = (g_game.w.res.y - (i + 1)) * buf_frm.s_l + (j * 4);
			index = i * w_bytes + j * 3;
			buf[index] = buf_frm.buf[buf_frm.pix];
			buf[index + 1] = buf_frm.buf[buf_frm.pix + 1];
			buf[index + 2] = buf_frm.buf[buf_frm.pix + 2];
		}
	}
	return (buf);
}

static void				write_all_data(t_bmp_h *head, t_bmp_i *i_head,
								unsigned char *buf, int fd)
{
	int i;

	i = 1;
	ft_memcpy(head, "BM", 2);
	i_head->b_size = 40;
	head->b_off_bits = 14 + i_head->b_size;
	head->b_size = head->b_off_bits + i_head->b_size_image;
	i_head->b_planes = 1;
	i_head->b_width = g_game.w.res.x;
	i_head->b_height = g_game.w.res.y;
	i_head->b_bit_count = BITCOUNT;
	if (i)
	{
		i = write(fd, head, sizeof(t_bmp_h));
		i = write(fd, i_head, sizeof(t_bmp_i));
		i = write(fd, buf, i_head->b_size_image);
	}
}

static char				write_header(int fd, void *frame)
{
	t_bmp_h			*head;
	t_bmp_i			*i_head;
	unsigned int	w_bytes;
	unsigned char	*buf;

	if (!(head = ft_calloc(1, sizeof(t_bmp_h))))
		return (MEM_ERROR);
	if (!(i_head = ft_calloc(1, sizeof(t_bmp_i))))
	{
		free(head);
		return (MEM_ERROR);
	}
	w_bytes = ((g_game.w.res.x * BITCOUNT + 31) / 32) * 4;
	i_head->b_size_image = w_bytes * g_game.w.res.y;
	if (!(buf = write_pxl_data(i_head->b_size_image, w_bytes, frame)))
		g_ecode = MEM_ERROR;
	else
	{
		write_all_data(head, i_head, buf, fd);
		free(buf);
	}
	free(head);
	free(i_head);
	return (NO_ERROR);
}

void					make_bmp(void)
{
	int		fd;
	void	*frame;

	g_game.w.mlx = mlx_init();
	frame = take_frame();
	if ((fd = open("cub3D.bmp", O_CREAT | O_WRONLY, 0644)) == -1)
	{
		mlx_destroy_image(g_game.w.mlx, frame);
		mlx_destroy_display(g_game.w.mlx);
		free(g_game.w.mlx);
		clear_cub();
		exit(out_err_arg(OPEN_ERROR));
	}
	if (write_header(fd, frame))
		out_err_arg(MEM_ERROR);
	mlx_destroy_image(g_game.w.mlx, frame);
	mlx_destroy_display(g_game.w.mlx);
	free(g_game.w.mlx);
	close(fd);
	clear_cub();
}
