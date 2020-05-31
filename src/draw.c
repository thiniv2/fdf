/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:59:30 by thinguye          #+#    #+#             */
/*   Updated: 2020/05/31 23:34:53 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_x(t_info *info, int y, int x)
{
	t_arr	***ptr;

	ptr = info->array;
	if (x < info->size_x - 1)
	{
		if ((*ptr)[y][x].color == RED && (*ptr)[y][x + 1].color == RED)
			info->color = RED;
		else if ((*ptr)[y][x].color == GREEN && (*ptr)[y][x + 1].color == GREEN)
			info->color = GREEN;
		else
			info->color = TEAL;
		draw_line(info, (*info->array)[y][x].x * info->zoom + info->p_x,
		(*info->array)[y][x].y * info->zoom + info->p_y,
		(*info->array)[y][x + 1].x * info->zoom + info->p_x,
		(*info->array)[y][x + 1].y * info->zoom + info->p_y);
	}
}

void	draw_y(t_info *info, int y, int x)
{
	t_arr	***ptr;

	ptr = info->array;
	if ((*ptr)[y][x].color == RED && (*ptr)[y + 1][x].color == RED)
		info->color = RED;
	else if ((*ptr)[y][x].color == GREEN && (*ptr)[y][x + 1].color == GREEN)
		info->color = GREEN;
	else
		info->color = TEAL;
	draw_line(info, (*info->array)[y][x].x * info->zoom + info->p_x,
	(*info->array)[y][x].y * info->zoom + info->p_y,
	(*info->array)[y + 1][x].x * info->zoom + info->p_x,
	(*info->array)[y + 1][x].y * info->zoom + info->p_y);
}

int		draw_grid(t_info *info, int x, int y)
{
	t_arr	***ptr;
	int		color;

	ptr = info->array;
	if (info->is_isometric == 1)
		apply_iso(info);
	if (info->is_isometric == 0)
		apply_parallel(info);
	while (y < info->size_y)
	{
		x = 0;
		while (x < info->size_x)
		{
			draw_x(info, y, x);
			if (y < info->size_y - 1)
				draw_y(info, y, x);
			x++;
		}
		y++;
	}
	show_buttons(info);
	return (0);
}

int		draw_line(t_info *info, int begin_x, int begin_y, int end_x, int end_y)
{
	double		delta_x;
	double		delta_y;
	double		pixel_x;
	double		pixel_y;
	double		pixels;

	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	pixel_x = begin_x;
	pixel_y = begin_y;
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
	return (0);
}
