/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:57:02 by yichan            #+#    #+#             */
/*   Updated: 2023/03/26 03:17:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_lexer(t_book *record)
{
	t_list	*token_itr;
	t_token *token_ptr;
	char	*check;

	token_itr = record->token;
	while (token_itr)
	{
		token_ptr = (t_token *)token_itr->content;
		check = ((t_token *)token_itr->content)->entity;
		// printf("%s\n", ((t_token *)token_itr->content)->entity);
		if (ft_strcmp("|", check))
			token_ptr->type = PIPE;
		if (ft_strcmp("?", check))
			token_ptr->type = QUERY;
		if (ft_strcmp("$", check))
			token_ptr->type = DOLLAR;
		if (ft_strcmp("<", check))
			token_ptr->type = LEFT;
		if (ft_strcmp(">", check))
			token_ptr->type = RIGHT;
		token_itr = token_itr->next;
	}
	return (0);
}