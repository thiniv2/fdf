/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 09:09:17 by thinguye          #+#    #+#             */
/*   Updated: 2019/11/04 16:16:44 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
		while (++i <= len)
			*(unsigned char*)(dst + (len - i)) =
			*(unsigned char*)(src + (len - i));
	else
		while (len-- > 0)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	return ((unsigned char*)dst);
}
