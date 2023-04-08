/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:54:15 by yichan            #+#    #+#             */
/*   Updated: 2023/04/08 16:08:56 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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