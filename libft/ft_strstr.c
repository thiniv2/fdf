/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:33:29 by thinguye          #+#    #+#             */
/*   Updated: 2019/10/21 16:19:48 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		counter;
	int		a;

	counter = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		counter = 0;
		a = i;
		while (haystack[a] == needle[counter])
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
