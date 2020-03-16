/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thien <thien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:09:08 by thinguye          #+#    #+#             */
/*   Updated: 2020/03/16 11:49:59 by thien            ###   ########.fr       */
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
			info->p_x = 250;
			info->p_y = 250;
		}
		else
		{
			info->p_x = 250;
			info->p_y = 250;
		}
	draw_grid(info, 0, 0);
}

int			deal_key(int keycode, t_info *info)
{

	printf("keycode: %d\n", keycode);

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
	if (keycode == KEY_R)
	{
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		printf("isometric 1 = %d\n", info->is_isometric);
		info->is_isometric = 2 ? 1 : 0;
		/*
		if (info->is_isometric == 2)
			info->is_isometric = 0;
		else
			info->is_isometric = 1;
		*/
		printf("isometric 2 = %d\n", info->is_isometric);
		reset_pos(info);
		draw_grid(info, 0, 0);
	}

	if (keycode == KEY_ESC)
		close_program(info);
	return (0);
}
