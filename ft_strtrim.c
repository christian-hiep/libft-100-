/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:39:23 by cvu               #+#    #+#             */
/*   Updated: 2023/02/04 08:39:27 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(s1 + i);
	while (len > 0 && ft_strchr(set, s1[i + len - 1]))
		len--;
	str = ft_substr(s1, i, len);
	if (str == NULL)
		return (NULL);
	return (str);
}
