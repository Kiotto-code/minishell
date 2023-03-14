/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/03/11 01:49:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	// t_token	*token;

	// token = 0;
	// token.entity = 0;
	// record->token = ft_lstnew(&token);
	// // token->anchor = 0;
	// record->token->content = &token;
	while (1)
	{
		record->input = readline("./minishell> ");
		if (record->input == NULL)
			exit(exit_status) ;
		ms_token(record);
		free(record->input);
	}
	return (0);
}
