/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:58:41 by mescobar          #+#    #+#             */
/*   Updated: 2023/06/07 11:23:31 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pipex.h"

void	ft_here_doc(t_pipex *list)
{
	char	*tmp;

	ft_printf("pipe heredoc> ");
	tmp = get_next_line(0);
	while (tmp && ft_strncmp(tmp, list->fonct_tab[1], ft_strlen(tmp) - 1) != 0)
	{
		ft_printf("pipe heredoc> ");
		ft_putstr_fd(tmp, list->file1);
		free(tmp);
		tmp = get_next_line(0);
	}
	if (tmp)
		free(tmp);
}

static void	first_child_2(t_pipex *list, char *fonct, char **envp)
{
	dup2(list->old_fd[0], 0);
	dup2(list->new_fd[1], 1);
	execute(fonct, envp);
	close(list->new_fd[1]);
	close(list->old_fd[0]);
}

static void	first_child(t_pipex *list, char *fonct, char **envp, int i)
{
	if (pipe(list->new_fd) < 0)
	{
		perror("Pipe error ");
		exit(EXIT_FAILURE);
	}
	if (i == 1 + list->here)
	{
		dup2(list->file1, 0);
		dup2(list->new_fd[1], 1);
		execute(fonct, envp);
		close(list->new_fd[1]);
	}
	else if (i != list->tab_long - 1)
		first_child_2(list, fonct, envp);
	else
	{
		dup2(list->old_fd[0], 0);
		dup2(list->file2, 1);
		execute(fonct, envp);
	}
	list->old_fd[0] = list->new_fd[0];
	list->old_fd[1] = list->new_fd[1];
}

void	pipex(t_pipex *list, char **envp)
{
	int		i;

	ft_open(list);
	i = 1 + list->here;
	while (list->fonct_tab[i] && i < list->tab_long)
	{
		first_child(list, list->fonct_tab[i], envp, i);
		i++;
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex		list;

	if (argc >= 4)
		ft_keepmain(&list, argc, argv, envp);
	else
	{
		perror("Invalid number of arguments");
		ft_printf("Please, give something like: (infile cmd1 cmd2 outfile)\n");
	}
	ft_free(&list);
	return (0);
}
