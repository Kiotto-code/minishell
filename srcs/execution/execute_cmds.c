/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:54:15 by yichan            #+#    #+#             */
/*   Updated: 2023/04/09 00:47:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_copy_to_array(t_env *env_copy)
{
	int		row_count;
	int		i;
	char	**env_arr;

	if (env_copy == NULL)
		return (NULL);
	row_count = env_copy_lstsize(env_copy);
	env_arr = (char **)malloc(sizeof(char *) * (row_count + 1));
	if (!env_arr)
		return (NULL);
	i = 0;
	while (env_copy && (row_count != 0))
	{
		env_arr[i] = ft_strdup(env_copy->var);
		i++;
		row_count--;
		env_copy = env_copy->next;
	}
	env_arr[i] = NULL;
	return (env_arr);
}

void	executing(t_book *mini, t_cmdl *cmds)
{
	char	*file;
	int		err;
	char	**env_arr;

	if (builtin_checker(cmds->command[0]))
	{
		// builtin_executing(mini, cmds);
		if (cmds->fork)
			exit (exit_status);
		return ;
	}
	else
	{
		env_arr = env_copy_to_array(mini->env);
		file = path_processing(mini, cmds->command[0]);
		if (!file)
			execve(cmds->command[0], cmds->command, env_arr);
		else
			execve(file, cmds->command, env_arr);
		err = errno;
		no_such_message(cmds->command[0]);
		free(file);
		array_liberator(env_arr);
		if (err == 13)
			exit(126);
		else
			exit(127);
	}
}

void	execute_child_process(t_book *mini, t_cmdl *cmds, t_cmdl *begin)
{
	fd_opening(cmds);
	if (heredoc_checking(cmds))
		heredoc_processing(cmds);
	if (execute_dup2(cmds))
		ft_putendl_fd("dup2 error", 2);
	while (begin->next)
	{
		close(begin->pipe_fd[0]);
		close(begin->pipe_fd[1]);
		begin = begin->next;
	}
	executing(mini, cmds);
}

void	wait_child_processes(t_cmdl *begin)
{
	t_cmdl	*cmd;
	int		status;

	status = 0;
	cmd = begin;
	while (begin->next)
	{
		close(begin->pipe_fd[0]);
		close(begin->pipe_fd[1]);
		begin = begin->next;
	}
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		exit_status = WEXITSTATUS(status);
		if (!exit_status && WIFSIGNALED(status))
			exit_status = 128 + WTERMSIG(status);
		cmd = cmd->next;
	}
}

void	execute_cmds(t_book *mini, t_cmdl *cmds)
{
	t_cmdl	*begin;

	begin = cmds;
	if (!cmds->next && builtin_checker(cmds->command[0]) && !cmds->redir)
	{
		executing(mini, cmds);
		return ;
	}
	if (pipe_creator(cmds))
		return ;
	while (cmds)
	{
		cmds->pid = fork();
		cmds->fork = 1;
		if (cmds->pid < 0)//unsuccessful fork
			error_msg("bash: fork: Resource temporarily unavailable");
		else if (cmds->pid == 0)
			execute_child_process(mini, cmds, begin);
		cmds = cmds->next;
	}
	wait_child_processes(begin);
}