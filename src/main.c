/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:37:25 by thinguye          #+#    #+#             */
/*   Updated: 2020/08/06 12:09:59 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				check_char(char c)
{
	if ((c >= 48 && c <= 57) ||
		(c == '-') || (c == ' '))
		return (1);
	return (0);
}

void			error_msg(int type)
{
	if (type == MALLOC)
		perror("malloc error");
	else if (type == OPEN)
		perror("open error");
	else if (type == MAP)
		ft_putendl("error: invalid map");
	else if (type == CHAR)
		ft_putendl("error: invalid characted in map");
	else if (type == ROW)
		ft_putendl("error: invalid row size");
	else if (type == END)
		ft_putendl("error: invalid character at the of line");
	else if (type == VERTEX)
		ft_putendl("error: vertex count does not match");
	else if (type == VALUE)
		ft_putendl("error: invalid value in map");
	else
		perror("error");
	exit(-1);
}

void			show_buttons(t_info *info)
{
	mlx_string_put(info->mlx_ptr, info->win_ptr,
	10, 10, 0xFFFFF, "R: Change projection");
	mlx_string_put(info->mlx_ptr, info->win_ptr,
	10, 30, 0xFFFFF, "arrow left/right decrease/increase height");
	mlx_string_put(info->mlx_ptr, info->win_ptr,
	10, 50, 0xFFFFF, "WASD: move around");
	mlx_string_put(info->mlx_ptr, info->win_ptr,
	10, 70, 0xFFFFF, "arrow up/down: zoom in/zoom out");
}

void			set_default_values(t_info *info)
{
	info->zoom = 30;
	info->p_x = 300;
	info->p_y = 300;
	info->z_axis = 1;
	info->is_isometric = 1;
}

int				main(int argc, char **argv)
{
	t_info		*info;
	t_arr		**arr;

	if (argc == 2)
	{
		if (!(info = (t_info*)malloc(sizeof(t_info))))
			error_msg(MALLOC);
		check_if_valid(argv);
		set_default_values(info);
		get_x_y(argv, info);
		info->mlx_ptr = mlx_init();
		info->win_ptr = mlx_new_window(info->mlx_ptr, 900, 900, "fdf");
		arr = create_int_arr(argv, info);
		info->array = &arr;
		draw_grid(info);
		mlx_key_hook(info->win_ptr, deal_key, info);
		mlx_loop(info->mlx_ptr);
	}
	else
		ft_putendl("usage: ./fdf <map_file.fdf>");
	return (0);
}
