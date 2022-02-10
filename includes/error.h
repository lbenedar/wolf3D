/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:06:45 by lbenedar          #+#    #+#             */
/*   Updated: 2021/02/14 23:47:25 by lbenedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "libft.h"

typedef	enum	e_errors
{
	NO_ERROR,
	TODO_ERROR,
	OPEN_ERROR = 3,
	PARSE_ERROR,
	GNL_ERROR,
	MEM_ERROR,
	MAP_ERROR,
	CUB_ERROR,
	ARG_ERROR,
	SPRITE_ERROR,
	PATH_ERROR,
	MLX_ERROR
}				t_errors;

t_errors		out_error(void);
t_errors		out_err_arg(t_errors err);

#endif
