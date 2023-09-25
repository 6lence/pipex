/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:08:56 by mescobar          #+#    #+#             */
/*   Updated: 2023/05/24 14:00:33 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = -1;
	while (s1[i + 1] == s2[i + 1])
		i++;
	if (i == ft_strlen(s2) && i == ft_strlen(s1))
		return (1);
	return (0);
}