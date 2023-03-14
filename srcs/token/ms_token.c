/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/03/11 20:31:39 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token		*ms_tokenrec(char *av, int *start, int *end)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token));
	if (!new)
		return (0);
	
	new->entity = ft_substr(av, *start, (*end) - (*start));
	// (void)start, (void)end;
	// new->entity = ft_strdup(av);
	// new->type = 123;
	// printf("str: %s \n", new->entity);
	new->type = 0;
	return (new);
}

void	ms_quotesplit(t_book *record)
{
	int				start;
	int				end;
	char			*av;
	t_list			*tokenitr;

	tokenitr = record->token;
	start = 0;
	av = ft_strjoin(record->input, " ");
	while (av[start] == ' ')
				start++;
	end = start;
	while (av[end])
	{
		if ((av[end] == ' ' && av[end -1] != ' ' && \
			record->anchor == NEUTRAL) || av[end +1] == 0)
		{
			while (av[start] == ' ')
				start++;
			ft_lstadd_back(&tokenitr,
				ft_lstnew(ms_tokenrec(av, &start, &end)));
			// printf("str :%s\n", ((t_token *)((t_list *)(tokenitr)->content))->entity);
			// printf("str :%d\n", ((t_token *)((t_list *)(tokenitr)->content))->type);
			// printf("strstu :%s\n", ((t_token *)((t_list *)(record->token)->content))->entity);
			// printf("str :%s\n", ((t_token *)((t_list *)record->token)->content)->entity);
			start = end;
		}
		printf("strqwe :%s\n", ((t_token *)((t_list *)(tokenitr)->content))->entity);
		printf("str :%d\n", ((t_token *)((t_list *)(tokenitr)->content))->type);
		// printf("strend :%s\n", ((t_token *)((t_list *)(tokenitr)->content))->entity);
		if (av[end] == '\'' && record->anchor == NEUTRAL)
			record->anchor = SQUOTE;
		else if (av[end] == '\'' && record->anchor == SQUOTE)
			record->anchor = NEUTRAL;
		else if (av[end] == '\"' && record->anchor == NEUTRAL)
			record->anchor = DQUOTE;
		else if (av[end] == '\"' && record->anchor == DQUOTE)
			record->anchor = NEUTRAL;
		(end)++;
	}
	// record->token->content = ft_lstnew(token);
}

int	ms_split(t_book *record)
{
	// t_token *token;
	t_list *itr;

	// token = 0;
	// record->token->content=ft_lstnew(token);
	ms_quotesplit(record);
	itr = (t_list *)(record->token);
	// printf("str: %s \n", ((t_token *)(itr->content))->entity);
	// printf("str :%s\n", ((t_token *)(itr->content))->entity);
	// printf("str: %s \n", ((t_token *)(record->token->next->content))->entity);
	// if (itr &&
	// 	((t_token *)(ft_lstlast(record->token))->content)->entity)
	// 	ft_lstdelone((ft_lstlast(record->token)), free);
	// printf("str: %s \n", ((t_token *)(itr->content))->entity);
	
	// while (ptr)
	// {
	// 	printf("str: %s \n", ptr->content);
	// 	ptr = ptr->next;
	// }
	return (0);
}

void	ms_token(t_book *record)
{
	ms_split(record);
	// ms_lexer(record, token);
	// token->av = av;
	
}