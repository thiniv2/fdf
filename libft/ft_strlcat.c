/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:30:03 by thinguye          #+#    #+#             */
/*   Updated: 2019/10/25 14:45:04 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	i = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (dstsize <= len1)
		return (len2 + dstsize);
	while (len1 + i < dstsize)
	{
		if (src[i] == '\0')
		{
			dst[len1 + i] = '\0';
			return (len1 + len2);
		}
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + (i - 1)] = '\0';
	return (len1 + len2);
}
