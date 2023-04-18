/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:12:59 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 19:59:19 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_heredoc(t_cmdl *cmd, char *stop)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!ft_strncmp(input, stop, ft_strlen(stop) + 1))
			break ;
		ft_putendl_fd(input, cmd->out);
		free(input);
	}
	close(cmd->out);
	exit(0);
}

void	heredoc_processing(t_cmdl *cmd)
{
	int		fd[2];
	int		pid;
	t_token	*tmp;

	tmp = (t_token *) cmd->redir;
	while (tmp)
	{
		if (pipe(fd) < 0)
		{
			perror("Error");
			exit_status = 1;
			exit (exit_status);
		}
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			cmd->out = fd[1];
			execute_heredoc(cmd, tmp->entity);
		}
		else
		{
			close(fd[1]);
			waitpid(pid, NULL, 0);
			cmd->in = fd[0];
		}
		tmp = tmp->next;
	}
}

int	heredoc_checking(t_cmdl *cmd)
{
	t_token	*tmp;

	if (!cmd->redir)
		return (0);
	tmp = (t_token *) cmd->redir;
	// if (ft_strcmp("<<", tmp->type) == 0)
	if (tmp->type == DLEFT)
		return (1);
	return (0);
}
