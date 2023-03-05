/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_inputloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:03:16 by yichan            #+#    #+#             */
/*   Updated: 2023/03/05 22:04:38 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_inputloop(t_book *record)
{
	t_token	token;

	record->token->content = &token;
	while (1)
	{
		record->input = readline("./minishell> ");
		if (record->input == NULL)
			break ;
		ms_token(&token, record);
		free(record->input);
	}
	return (0);
}
