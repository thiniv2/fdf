/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:05:50 by thinguye          #+#    #+#             */
/*   Updated: 2019/11/04 16:22:25 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (s1 && s2)
	{
		str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
		if (!str)
			return (NULL);
		ft_strcpy(str, s1);
		i = ft_strlen(s1);
		ft_strcpy((str + i), s2);
		return (str);
	}
	return (0);
}
