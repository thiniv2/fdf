/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:24:07 by thinguye          #+#    #+#             */
/*   Updated: 2019/10/25 08:06:23 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	counter;

	counter = 0;
	a = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (i < len)
	{
		counter = 0;
		a = i;
		while (haystack[a] == needle[counter] && a < len)
		{
			counter++;
			a = i + counter;
			if (needle[counter] == '\0')
				return ((char*)(haystack + a - counter));
		}
		i++;
	}
	return (NULL);
}
