/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/03/22 23:19:55 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	while (1)
	{
		record->input = readline("./minishell> ");
		if (record->input == NULL)
			exit(exit_status) ;
		ms_token(record);
		// printf("strqwe :%s\n", ((t_token *)(record->token->content))->entity);
		free(record->input);
	}
	return (0);
}
