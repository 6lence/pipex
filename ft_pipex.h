/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:57:37 by mescobar          #+#    #+#             */
/*   Updated: 2023/06/07 11:32:06 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "src/printf/ft_printf.h"
# include "src/gnl/get_next_line_bonus.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	int		old_fd[2];
	int		new_fd[2];
	int		file1;
	int		file2;
	char	**fonct_tab;
	int		tab_long;
	int		tmp;
	pid_t	proc;
	int		proc_status;
	int		here;
}			t_pipex;

void	ft_open(t_pipex *list);
void	execute(char *fonct, char **envp);
char	*tab_maker(char *arg);
void	ft_here_doc(t_pipex *list);
void	pipex(t_pipex *list, char **envp);
void	ft_free(t_pipex *list);
void	ft_keepmain(t_pipex *list, int argc, char *argv[], char **envp);
void	ft_error(char *str);

#endif
