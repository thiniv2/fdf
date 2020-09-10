/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:37:18 by thinguye          #+#    #+#             */
/*   Updated: 2020/07/28 15:18:08 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LINUX_H
# define FDF_LINUX_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# define GREEN 0x00FF00
# define RED 0xFC030B
# define TEAL 0xFFFFF
# define WHITE 0xFFFFFF
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
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct			s_arr
{
	float				x;
	float				y;
	float				z;
	float				color;
}						t_arr;

typedef struct			s_info
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	float				heigth;
	float				width;
	float				z_axis;
	float				zoom;
	float				p_x;
	float				p_y;
	int					is_isometric;
	int					max_vertexes_x;
	float				color;
	t_arr				***array;
}						t_info;

enum			e_type
{
	MALLOC = 0,
	OPEN = 1,
	MAP = 2,
	CHAR = 3,
	ROW = 4,
	END = 5,
	VERTEX = 6,
	VALUE = 7,
};

void					get_x_y(char **argv, t_info *info);
void					draw_line(t_info *info, int *int_ptr);
void					draw_grid(t_info *info);
void					error_msg();
void					check_if_valid(char **argv);
void					show_buttons(t_info *info);
t_arr					**create_int_arr(char **argv, t_info *info);
int						deal_key(int keycode, t_info *info);
int						check_char(char c);
int						get_x(char *str);
void					apply_height(t_info *info, int key);
void					apply_iso(t_info *info);
void					apply_parallel(t_info *info);
#endif
