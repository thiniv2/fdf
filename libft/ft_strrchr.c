/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:24:51 by thinguye          #+#    #+#             */
/*   Updated: 2019/10/21 18:00:24 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*location;

	location = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			location = ((char*)(str + i));
		i++;
	}
	if (str[i] == c && c == '\0')
		location = ((char*)(str + i));
	return (location);
}
