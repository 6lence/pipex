/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:12:31 by mescobar          #+#    #+#             */
/*   Updated: 2023/05/24 11:42:02 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *src, size_t n)
{
	size_t	i;
	char	*dest;

	dest = ft_calloc(sizeof(char), n + 1);
	i = -1;
	while (i++ <= n)
		dest[i] = src[i];
	free(src);
	return (dest);
}
