/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:39:01 by cvu               #+#    #+#             */
/*   Updated: 2023/02/04 08:39:03 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	char	*save;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		len = ft_strlen(s2) + 1;
	else if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(*str) * (len));
	if (str == NULL)
		return (NULL);
	save = str;
	if (s1)
		while (*s1)
			*str++ = *s1++;
	if (s2)
		while (*s2)
			*str++ = *s2++;
	*str = 0;
	return (save);
}
