/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thien <thien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:37:00 by thinguye          #+#    #+#             */
/*   Updated: 2020/03/16 13:10:31 by thien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_x(char *str, t_info *info)
{
	int		i;
	int		len;
	int		*int_line;

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
	return(len);
}

size_t	nbr_length(int n)
{
	size_t	counter;
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

t_arr	**create_int_arr(char **argv, t_info *info)
{
	t_arr	**arr;
	char	*line;
	int		x;
	int		y;
	int		i;
	int		fd;
	int		j;

	j = 0;
	y = 0;
	i = 0;
	if (!(arr = (t_arr**)malloc(sizeof(t_arr*) * (info->size_y))))
		error_msg();
	fd = open(argv[1], O_RDONLY);
	while (y < info->size_y)
	{
		get_next_line(fd, &line);
		if (!(arr[y] = (t_arr*)malloc(sizeof(t_arr) * (info->size_x))))
			error_msg();
		x = 0;
		while (x < info->size_x)
		{
			arr[y][x].x = x;
			arr[y][x].y = y;
			while (ft_isalnum(*line) == 0 && *line && *line != '-')
				line++;
			if (*line)
			{
				arr[y][x].z = ft_atoi(line);
				printf("z = %f\n", arr[y][x].z);
				if (arr[y][x].z > 0)
					arr[y][x].color = RED;
				else if (arr[y][x].z == 0)
					arr[y][x].color = GREEN;
				else
					arr[y][x].color = TEAL;
			}
			while (ft_isdigit(*line) && *line)
				line++;
			x++;
		}
		y++;
	}
	close(fd);
	return(arr);
}

void	get_x_y(char **argv, t_info *info)
{
	char	*line;
	int		x;
	int		y;
	int		fd;

	x = 0;
	y = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		info->size_y = info->size_y + 1;
		if (!info->size_x)
			info->size_x = get_x(line, info);
		free(line);
	}
	close(fd);
}