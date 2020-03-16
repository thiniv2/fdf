/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thien <thien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:52:31 by thinguye          #+#    #+#             */
/*   Updated: 2020/01/16 08:46:49 by thien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = NULL;
	if (s)
	{
		if (!(mem = ft_strnew(len)))
			return (NULL);
		while (i < len)
		{
			mem[i] = s[start];
			i++;
			start++;
		}
	}
	return (mem);
}
