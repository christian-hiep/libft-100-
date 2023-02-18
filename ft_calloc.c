/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:35:08 by cvu               #+#    #+#             */
/*   Updated: 2023/02/15 00:33:43 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb > 0 && size > 0 && nmemb > 1000000000 / size)
	{
		return (NULL);
	}
	result = malloc(nmemb * size);
	if (!result)
	{
		return (0);
	}
	ft_bzero(result, nmemb * size);
	return (result);
}
