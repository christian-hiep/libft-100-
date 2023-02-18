/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:34:01 by cvu               #+#    #+#             */
/*   Updated: 2023/02/04 08:34:04 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*bptr;
	char		*lptr;

	if (!*little)
		return ((char *)big);
	while (len-- && *big)
	{
		if (*big == *little)
		{
			i = len;
			bptr = (char *)big + 1;
			lptr = (char *)little + 1;
			while (i-- && *bptr && *lptr && *lptr == *bptr)
			{
				++lptr;
				++bptr;
			}
			if (*lptr == '\0')
				return ((char *)big);
		}
		++big;
	}
	return (NULL);
}
