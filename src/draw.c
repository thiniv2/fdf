/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:59:30 by thinguye          #+#    #+#             */
/*   Updated: 2020/07/28 15:18:08 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				*init_list(int begin_x, int begin_y, int end_x, int end_y)
{
	int		*ptr;

	if (!(ptr = (int*)malloc(sizeof(int) * 4)))
		error_msg(MALLOC);
	ptr[0] = begin_x;
	ptr[1] = begin_y;
	ptr[2] = end_x;
	ptr[3] = end_y;
	return (ptr);
}

void			draw_x(t_info *info, int y, int x)
{
	t_arr	***ptr;
	int		*tmp_list;

	ptr = info->array;
	tmp_list = init_list((*ptr)[y][x].x * info->zoom + info->p_x,
		(*ptr)[y][x].y * info->zoom + info->p_y,
		(*ptr)[y][x + 1].x * info->zoom + info->p_x,
		(*ptr)[y][x + 1].y * info->zoom + info->p_y);
	if (x < info->width - 1)
	{
		if ((*ptr)[y][x].color == RED && (*ptr)[y][x + 1].color == RED)
			info->color = RED;
		else if ((*ptr)[y][x].color == GREEN && (*ptr)[y][x + 1].color == GREEN)
			info->color = GREEN;
		else if ((*ptr)[y][x].color == TEAL && (*ptr)[y][x + 1].color == TEAL)
			info->color = TEAL;
		else
			info->color = WHITE;
		draw_line(info, tmp_list);
	}
	free(tmp_list);
}

void			draw_y(t_info *info, int y, int x)
{
	t_arr	***ptr;
	int		*tmp_list;

	ptr = info->array;
	tmp_list = init_list((*ptr)[y][x].x * info->zoom + info->p_x,
		(*ptr)[y][x].y * info->zoom + info->p_y,
		(*ptr)[y + 1][x].x * info->zoom + info->p_x,
		(*ptr)[y + 1][x].y * info->zoom + info->p_y);
	if ((*ptr)[y][x].color == RED && (*ptr)[y + 1][x].color == RED)
		info->color = RED;
	else if ((*ptr)[y][x].color == GREEN && (*ptr)[y + 1][x].color == GREEN)
		info->color = GREEN;
	else if ((*ptr)[y][x].color == TEAL && (*ptr)[y + 1][x].color == TEAL)
		info->color = TEAL;
	else
		info->color = WHITE;
	draw_line(info, tmp_list);
	free(tmp_list);
}

void			draw_grid(t_info *info)
{
	int		x;
	int		y;

	y = 0;
	if (info->is_isometric == 1)
		apply_iso(info);
	if (info->is_isometric == 0)
		apply_parallel(info);
	while (y < info->heigth)
	{
		x = 0;
		while (x < info->width)
		{
			draw_x(info, y, x);
			if (y < info->heigth - 1)
				draw_y(info, y, x);
			x++;
		}
		y++;
	}
	show_buttons(info);
}

void			draw_line(t_info *info, int *int_ptr)
{
	float		delta_x;
	float		delta_y;
	float		pixel_x;
	float		pixel_y;
	float		pixels;

	delta_x = int_ptr[2] - int_ptr[0];
	delta_y = int_ptr[3] - int_ptr[1];
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	pixel_x = int_ptr[0];
	pixel_y = int_ptr[1];
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels > 0)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr,
		pixel_x, pixel_y, info->color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
