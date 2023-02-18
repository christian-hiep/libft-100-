/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:08:28 by cvu               #+#    #+#             */
/*   Updated: 2023/02/18 10:08:34 by cvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeup(char **strs)
{
	int	i;

	i = 0;
	if (strs != NULL)
	{
		while (strs[i] != NULL)
		{
			if (strs[i] != NULL)
				free(strs[i]);
			i++;
		}
		free(strs);
	}
}

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

static void	ft_strcpy(char *word, const char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		word[i] = str[j + i];
		i++;
	}
	word[i] = '\0';
}

static char	*ft_stralloc(const char *str, char c, int *k)
{
	char	*word;
	int		len;
	int		j;

	len = 0;
	j = *k;
	word = NULL;
	while (str[*k] != '\0')
	{
		if (str[*k] != c)
		{
			while (str[*k + len] != '\0' && str[*k + len] != c)
				len++;
			word = (char *)malloc(sizeof(char) * (len + 1));
			if (word == NULL)
				return (NULL);
			ft_strcpy(word, str, c, j);
			*k += len;
			return (word);
		}
		*k += 1;
	}
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	char	**strs;
	int		pos;

	if (!str)
		return (NULL);
	j = ft_wordcount(str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (!strs)
		return (NULL);
	i = 0;
	pos = 0;
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(str, c, &pos);
		if (strs[i] == NULL)
		{
			ft_freeup(strs);
			return (NULL);
		}
		i++;
	}
	return (strs);
}
