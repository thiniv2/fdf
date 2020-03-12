/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:52:31 by thinguye          #+#    #+#             */
/*   Updated: 2019/11/12 16:14:58 by thinguye         ###   ########.fr       */
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
		if (start < 0 || len < 0)
			return (NULL);
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
