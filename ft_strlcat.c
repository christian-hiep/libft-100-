/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:28:41 by cvu               #+#    #+#             */
/*   Updated: 2023/02/04 08:28:44 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= size)
		return (srclen + size);
	if (destlen + srclen < size)
		ft_memcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + destlen, src, size - destlen - 1);
		dest[size - 1] = '\0';
	}
	return (destlen + srclen);
}
