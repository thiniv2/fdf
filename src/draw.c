/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:59:30 by thinguye          #+#    #+#             */
/*   Updated: 2020/03/12 15:14:30 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_iso(t_info *info)
{
	int		x;
	int		y;
	float	prev_x;
	float	prev_y;
	t_arr	***ptr;

	ptr = info->array;
	y = 0;
	x = 0;
	while (y < info->size_y)
	{
		x = 0;
		while (x < info->size_x)
		{
			prev_x = (*ptr)[y][x].x;
    		prev_y = (*ptr)[y][x].y;
			(*ptr)[y][x].x = (prev_x - prev_y) * cos(0.523599);
			(*ptr)[y][x].y = -(*ptr)[y][x].z + (prev_x + prev_y) * sin(0.523599);
			x++;
		}
		y++;
	}
	info->is_isometric = 0;
}

int		draw_grid(t_info *info, int x, int y)
{
	t_arr	***ptr;	
	int		color;

	ptr = info->array;
	color = (*ptr)[0][0].color;
	if (info->is_isometric == 1)
		apply_iso(info);
	while (y < info->size_y)
	{
		x = 0;
		while (x < info->size_x)
		{
			if (x < info->size_x - 1)
			{
				if ((*ptr)[y][x].color == RED && (*ptr)[y][x + 1].color == RED)
					color = RED;
				else
					color = TEAL;
				draw_line(info, (*ptr)[y][x].x * info->zoom + info->p_x,
					(*ptr)[y][x].y * info->zoom + info->p_y,
					(*ptr)[y][x + 1].x * info->zoom + info->p_x,
					(*ptr)[y][x + 1].y * info->zoom + info->p_y, color);
			}
			if (y < info->size_y - 1)
			{
				if ((*ptr)[y][x].color == RED && (*ptr)[y + 1][x].color == RED)
					color = RED;
				else
					color = TEAL;
				draw_line(info, (*ptr)[y][x].x * info->zoom + info->p_x,
					(*ptr)[y][x].y * info->zoom + info->p_y,
					(*ptr)[y + 1][x].x * info->zoom + info->p_x,
					(*ptr)[y + 1][x].y * info->zoom + info->p_y, color);
			}
			x++;
		}
		y++;
	}
	show_buttons(info);
	return (0);
}

int		draw_line(t_info *info, int beginX, int beginY, int endX, int endY, int color)
{
	double		delta_x;
	double		delta_y;
	double		pixel_x;
	double		pixel_y;
	double		pixels;

	delta_x = endX - beginX;
	delta_y = endY - beginY;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	pixel_x = beginX;
	pixel_y = beginY;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels > 0)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
	return (0);
}