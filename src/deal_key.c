/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:09:08 by thinguye          #+#    #+#             */
/*   Updated: 2020/03/12 15:18:44 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		close_program(t_info *info)
{
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		exit(0);
}

void		reset_pos(t_info *info)
{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->zoom = 15;
		if (info->is_isometric == 1)
		{
			info->p_x = 400;
			info->p_y = 100;
		}
		else
		{
			info->p_x = 100;
			info->p_y = 100;
		}
	draw_grid(info, 0, 0);
}

int			deal_key(int keycode, t_info *info)
{
	if (keycode == KEY_UP)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->zoom *= 1.25;
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_DOWN)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->zoom *= 0.8;
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_LEFT)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_D)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->p_x += 25;
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_A)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->p_x -= 25;
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_W)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->p_y -= 25;
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_S)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->p_y += 25;
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_I)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->is_isometric = 1;
		reset_pos(info);
		draw_grid(info, 0, 0);
	}
	if (keycode == KEY_P)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		info->is_isometric = 0;
		reset_pos(info);
		draw_grid(info, 0, 0);
	}
	
	if (keycode == KEY_ESC)
		close_program(info);
	return (0);
}
