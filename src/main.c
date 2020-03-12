/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:37:25 by thinguye          #+#    #+#             */
/*   Updated: 2020/03/12 15:11:40 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		error_msg()
{
	perror("Error");
	return (-1);
}

void		show_buttons(t_info *info)
{
	mlx_string_put(info->mlx_ptr, info->win_ptr, 10, 10, 0xFFFFF, "I: isometric");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 10, 25, 0xFFFFF, "P: parallel");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 10, 55, 0xFFFFF, "WASD: move around");
	mlx_string_put(info->mlx_ptr, info->win_ptr, 10, 70, 0xFFFFF, "arrow up/down: zoom in/zoom out");
}

int			main(int argc, char **argv)
{
	t_info 		*info;
	t_arr		**arr;
	int			x;
	int			y;

	x = 0;
	y = 0;

	if (argc != 2)
	{
		ft_putendl("usage: /fdf <map_file.fdf>");
		return (1);
	}
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		error_msg();
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 800, 800, "fdf");
	info->zoom = 20;
	info->p_x = 100;
	info->p_y = 200;
	info->is_isometric = 0;
	get_x_y(argv, info);
	arr = create_int_arr(argv, info);
	info->array = &arr;
	draw_grid(info, 0, 0);
	mlx_key_hook(info->win_ptr, deal_key, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}
