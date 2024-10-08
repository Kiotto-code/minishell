/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 22:09:30 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		sigs_interactive_shell();
		record->input = readline("./minishell> ");
		if (record->input == NULL)
			exit(exit_status);
		if (*record->input)
			add_history(record->input);
		if (validator(record->input) == 0)
		{
			ms_token(record);
			ms_lexer(record);
		}
		sigs_non_interactive_shell();
		if (record->input)
			execute_cmds(record, record->cmds);
		// printf("strqwe :%s\n", ((t_token *)(record->token->content))->entity);
		free(record->input);
		record->input = 0;
		liberator(record);
	}
	liberator(record);
	return (0);
}
