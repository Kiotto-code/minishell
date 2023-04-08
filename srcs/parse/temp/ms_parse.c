/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:11:18 by yichan            #+#    #+#             */
/*   Updated: 2023/04/07 22:18:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_book *mini, t_env *env_copy)
{
	(void)env_copy;
	mini->input = readline(BEGIN(49, 32)"[minishell ]$ "CLOSE);
	if (!mini->input)
		exit(exit_status);
	if (*mini->input)
		add_history (mini->input);
	if (validator(mini->input) == 0)
	{
		mini->args = arguments_processing(mini);
		mini->cmds = commands_processing(mini);
	}
	free(mini->input);
	mini->input = NULL;
}
