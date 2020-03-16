/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thien <thien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:38:16 by thinguye          #+#    #+#             */
/*   Updated: 2020/01/16 08:47:16 by thien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (*(char*)(str + i))
	{
		if (str[i] == (char)c)
			return ((char*)(str + i));
		i++;
	}
	if ((char)str[i] == '\0' || (char)c == '\0')
		return ((char*)(str + i));
	return (NULL);
}
