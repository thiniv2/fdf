/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:37:18 by thinguye          #+#    #+#             */
/*   Updated: 2020/05/31 23:35:04 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "../minilibx/minilibx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define MAGENTA 0xFF00FF
# define RED 0xFC030B
# define TEAL 0xFFFFF
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_R 114
# define KEY_Q 113
# define KEY_E 101
# define ROTATION_DEG 0.05

#include <stdio.h> //DELETE

typedef struct		s_arr
{
	double			x;
	double			y;
	double			z;
	double			color;
}					t_arr;

typedef struct		s_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	double		size_y;
	double		size_x;
	double	zoom;
	double	p_x;
	double	p_y;
	int		is_isometric;
	int		color;
	t_arr	***array;
}					t_info;

void		get_x_y(char **argv, t_info *info);
int			draw_line(t_info *info, int beginX, int beginY, int endX, int endY);
int			draw_grid(t_info *info, int x, int y);
int			error_msg();
int			get_x(char *str, t_info *info);
void		show_buttons(t_info *info);
t_arr		**create_int_arr(char **argv, t_info *info);
int			deal_key(int keycode, t_info *info);
void		apply_height(t_info *info, int key);
void		apply_iso(t_info *info);
void		apply_parallel(t_info *info);
#endif
