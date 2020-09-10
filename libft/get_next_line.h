/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:42:05 by thinguye          #+#    #+#             */
/*   Updated: 2020/07/03 12:20:24 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 5000000
# define MAX_FD 10240

int		get_next_line(const int fd, char **line);
#endif
