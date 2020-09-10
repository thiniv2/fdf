/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:10:54 by thinguye          #+#    #+#             */
/*   Updated: 2020/08/06 12:30:18 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

long			ft_atol(const char *str)
{
	int		i;
	int		isnegative;
	long	res;

	isnegative = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		isnegative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - '0');
	res = res * isnegative;
	return (res);
}

int				vertex_count(char *line)
{
	int		i;
	int		vertexes;

	i = 0;
	vertexes = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			vertexes++;
			while (line[i] && ft_isdigit(line[i]))
				i++;
		}
	}
	return (vertexes);
}

int				check_vertexes(char *line)
{
	static int	max_vertex;

	if (max_vertex == 0)
		max_vertex = vertex_count(line);
	if (max_vertex < 2)
		error_msg(MAP);
	if (vertex_count(line) != max_vertex && vertex_count(line) != 0)
		return (0);
	return (1);
}

void			check_errors(char *line, int x)
{
	if (check_char(line[x]) == 0)
		error_msg(CHAR);
	if (line[x + 1] == '\0' && !ft_isdigit(line[x]))
		error_msg(END);
	if (ft_atol(line + x) > MAX_INT || ft_atol(line + x) < MIN_INT)
		error_msg(VALUE);
}

void			check_if_valid(char **argv)
{
	int		fd;
	int		x;
	char	*line;

	if ((fd = open(argv[1], O_RDWR)) < 0)
		error_msg(OPEN);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		if (line[0] == '\0')
			error_msg(MAP);
		if (check_vertexes(line) == 0)
			error_msg(VERTEX);
		while (line[x])
		{
			check_errors(line, x);
			x++;
		}
		free(line);
	}
	if (check_vertexes(line) == 0)
		error_msg(MAP);
	close(fd);
}
