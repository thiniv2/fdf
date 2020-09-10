/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:32:12 by thinguye          #+#    #+#             */
/*   Updated: 2020/07/28 15:18:08 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		apply_iso(t_info *info)
{
	int		x;
	int		y;
	float	prev_x;
	float	prev_y;
	t_arr	***ptr;

	ptr = info->array;
	y = 0;
	x = 0;
	while (y < info->heigth)
	{
		x = 0;
		while (x < info->width)
		{
			prev_x = (*ptr)[y][x].x;
			prev_y = (*ptr)[y][x].y;
			(*ptr)[y][x].x = (prev_x - prev_y) * cos(0.523599);
			(*ptr)[y][x].y = -(*ptr)[y][x].z * info->z_axis +
			(prev_x + prev_y) * sin(0.523599);
			x++;
		}
		y++;
	}
	info->is_isometric = 2;
}

void		apply_parallel(t_info *info)
{
	int		x;
	int		y;
	t_arr	***ptr;

	ptr = info->array;
	y = 0;
	x = 0;
	while (y < info->heigth)
	{
		x = 0;
		while (x < info->width)
		{
			(*ptr)[y][x].x = x;
			(*ptr)[y][x].y = y;
			x++;
		}
		y++;
	}
}
