/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:28:58 by mescobar          #+#    #+#             */
/*   Updated: 2023/06/07 11:29:55 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pipex.h"

void	ft_open(t_pipex *list)
{
	if (list->here == 1)
	{
		if (pipe(list->old_fd))
			ft_error("Pipe error ");
		list->file1 = list->old_fd[1];
		ft_here_doc(list);
		close(list->old_fd[1]);
		list->file1 = list->old_fd[0];
	}
	else
		list->file1 = open(list->fonct_tab[0], O_RDONLY, 0644);
	list->file2 = open(list->fonct_tab[list->tab_long],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (list->file1 < 0)
		ft_error("Error opening first file ");
	else if (list->file2 < 0)
		ft_error("Error opening second file ");
}

char	*tab_maker(char *arg)
{
	int		i;
	char	*tmp;

	tmp = ft_calloc(ft_strlen(arg), sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		tmp[i] = arg[i];
		i++;
	}
	return (tmp);
}

void	execute(char *fonct, char **envp)
{
	char	*path;
	char	**split;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		split = ft_split(fonct, ' ');
		path = ft_strjoin("/usr/bin/", split[0]);
		if (access(path, 0) == 0)
			execve(path, split, envp);
		else
		{
			perror("Pathway error ");
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, NULL, 0);
}

void	ft_free(t_pipex *list)
{
	int	i;

	i = 0;
	while (list->fonct_tab[i])
		free(list->fonct_tab[i++]);
	free(list->fonct_tab);
	close(list->file1);
	close(list->old_fd[0]);
	close(list->old_fd[1]);
	close(list->file2);
}

void	ft_keepmain(t_pipex *list, int argc, char *argv[], char **envp)
{
	int	i;

	list->fonct_tab = (char **)ft_calloc(argc + 1, sizeof(char *));
	i = 0;
	while (i < argc - 1)
	{
		list->fonct_tab[i] = tab_maker(argv[i + 1]);
		i++;
	}
	list->fonct_tab[i] = NULL;
	list->here = ft_strcmp(list->fonct_tab[0], "here_doc");
	list->tab_long = argc - (2 + ft_strcmp(list->fonct_tab[1], "here_doc"));
	pipex(list, envp);
}
