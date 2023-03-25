/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:57:02 by yichan            #+#    #+#             */
/*   Updated: 2023/03/26 04:18:28 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_lexer(t_book *record)
{
	t_list	*token_itr;
	t_token *token_ptr;
	char	*check;
	const t_token	arr[] = {
	{.entity = "|", .type = PIPE},
	{.entity = "?", .type = QUERY},
	{.entity = "$", .type = DOLLAR},
	{.entity = "<", .type = RIGHT},
	{.entity = ">", .type = LEFT},
	};

	token_itr = record->token;
	while (token_itr)
	{
		token_ptr = (t_token *)token_itr->content;
		check = ((t_token *)token_itr->content)->entity;
		token_ptr->type = LITERAL;
		for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
		{
			if (!ft_strcmp(arr[i].entity, check))
				token_ptr->type = arr[i].type;
		}
		printf("token:%s type:%d\n", ((t_token *)token_itr->content)->entity, token_ptr->type);
		token_itr = token_itr->next;
	}
	return (0);
}
		// if (ft_strcmp("|", check))
		// 	token_ptr->type = PIPE;
		// else if (ft_strcmp("?", check))
		// 	token_ptr->type = QUERY;
		// else if (ft_strcmp("$", check))
		// 	token_ptr->type = DOLLAR;
		// else if (ft_strcmp("<", check))
		// 	token_ptr->type = LEFT;
		// else if (ft_strcmp(">", check))
		// 	token_ptr->type = RIGHT;
		// else
		// 	token_ptr->type = LITERAL;