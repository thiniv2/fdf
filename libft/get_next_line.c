/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:41:55 by thinguye          #+#    #+#             */
/*   Updated: 2020/07/03 12:06:06 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_new_line(int fd, char **line, char **str)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + len + 1)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str[MAX_FD];
	char			*ptr;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fd > MAX_FD)
		return (-1);
	if (str[fd] == NULL)
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(ptr = ft_strjoin(str[fd], buf)))
			return (-1);
		free(str[fd]);
		str[fd] = ptr;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd][0] == '\0'))
		return (0);
	return (ft_new_line(fd, line, str));
}
