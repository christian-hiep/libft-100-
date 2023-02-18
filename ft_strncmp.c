/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:32:43 by cvu               #+#    #+#             */
/*   Updated: 2023/02/04 08:32:46 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp_char(const unsigned char c1, const unsigned char c2)
{
	if (c1 != c2)
		return (c1 - c2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		cmp = cmp_char((unsigned char)s1[i], (unsigned char)s2[i]);
		if (cmp != 0)
			return (cmp);
		i++;
	}
	if (i < n)
	{
		cmp = cmp_char((unsigned char)s1[i], (unsigned char)s2[i]);
		return (cmp);
	}
	return (0);
}
