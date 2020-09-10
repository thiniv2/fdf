/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:37:00 by thinguye          #+#    #+#             */
/*   Updated: 2020/08/06 12:14:29 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_x(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			len++;
		}
		else
			i++;
	}
	return (len);
}

size_t	nbr_length(int n)
{
	size_t		counter;
	size_t		i;

	i = 1;
	counter = n;
	while (counter != 0)
	{
		counter = counter / 10;
		i++;
	}
	return (i);
}

void	set_color(t_arr **arr, char *line, int y, int x)
{
	static int i;

	arr[y][x].x = x;
	arr[y][x].y = y;
	while (ft_isalnum(line[i]) == 0 && line[i] && line[i] != '-')
		i = i + 1;
	if (line[i])
	{
		arr[y][x].z = ft_atoi(line + i) / 4.0;
		if (arr[y][x].z > 0)
			arr[y][x].color = RED;
		else if (arr[y][x].z == 0)
			arr[y][x].color = GREEN;
		else
			arr[y][x].color = TEAL;
	}
	while (ft_isdigit(line[i]) || line[i] == '-')
		i = i + 1;
	if (line[i] == '\0')
		i = 0;
}

t_arr	**create_int_arr(char **argv, t_info *info)
{
	t_arr	**arr;
	char	*line;
	int		x;
	int		y;
	int		fd;

	y = 0;
	if (!(arr = (t_arr**)malloc(sizeof(t_arr*) * (info->heigth))))
		error_msg(MALLOC);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_msg(OPEN);
	while (y < info->heigth)
	{
		get_next_line(fd, &line);
		if (!(arr[y] = (t_arr*)malloc(sizeof(t_arr) * (info->width))))
			error_msg(MALLOC);
		x = -1;
		while (++x < info->width)
			set_color(arr, line, y, x);
		free(line);
		y++;
	}
	close(fd);
	return (arr);
}

void	get_x_y(char **argv, t_info *info)
{
	char	*line;
	int		x;
	int		fd;

	x = 0;
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_msg(OPEN);
	while (get_next_line(fd, &line) > 0)
	{
		info->heigth++;
		if (!info->width)
			info->width = get_x(line);
		free(line);
	}
	close(fd);
}
