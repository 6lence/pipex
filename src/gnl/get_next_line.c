/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:08:22 by mescobar          #+#    #+#             */
/*   Updated: 2023/05/24 16:20:51 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_remove_string(char *string, int i)
{
	char	*tmp;

	if (string[0] == '\0')
	{
		free(string);
		return (NULL);
	}
	tmp = ft_substr(string, i, ft_strlen(string));
	free(string);
	return (tmp);
}

static char	*ft_string(char *string)
{
	int		i;
	char	*send;

	if (!string || string[0] == '\0')
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i])
		i++;
	send = ft_calloc(sizeof(char), (i + 2));
	if (!send)
		return (NULL);
	i = 0;
	while (string[i] != '\n' && string[i] != '\0')
	{
		send[i] = string[i];
		i++;
	}
	if (string[i] == '\0')
		send[i] = '\0';
	else if (string[i] == '\n')
		send[i] = '\n';
	return (send);
}

static int	ft_in(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_send(char *string, int fd)
{
	int		i;
	char	*buff;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (i > 0 && ft_in(string) == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		string = ft_strrjoin(string, buff);
	}
	free(buff);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string = NULL;
	char		*send;
	int			i;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	string = ft_send(string, fd);
	send = ft_string(string);
	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\n' && string[i] != '\0')
		i++;
	string = ft_remove_string(string, i + 1);
	return (send);
}
