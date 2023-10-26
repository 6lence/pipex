/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 09:10:16 by mescobar          #+#    #+#             */
/*   Updated: 2023/05/24 15:58:49 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;

	s2 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*scop;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		scop = (char *)ft_calloc((ft_strlen(s + start) + 1), sizeof(char));
	else
		scop = (char *)ft_calloc(len + 1, sizeof(char));
	if (!scop)
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (j < len && s[i])
	{
		scop[j] = ((char *)s)[i];
		i++;
		j++;
	}
	return (scop);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pt;
	size_t	useless;
	size_t	i;

	useless = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (useless / size != nmemb || useless / nmemb != size)
		return (NULL);
	pt = malloc(useless);
	i = 0;
	if (!pt)
		return (NULL);
	while (i < useless)
		pt[i++] = '\0';
	return ((void *)pt);
}

char	*ft_strrjoin(char const *s1, char const *s2)
{
	char		*chain;
	size_t		len;
	size_t		i;
	char		*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	chain = (char *)ft_calloc(len, sizeof(char));
	if (!chain)
		return (NULL);
	i = 0;
	str = (char *)s1;
	while (*s1)
		chain[i++] = *s1++;
	while (*s2)
		chain[i++] = *s2++;
	free(str);
	return (chain);
}
