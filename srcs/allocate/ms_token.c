/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/03/09 03:12:23 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ms_tokenrec(char *av, int *start, int *end)
{
	char	*ret;
	t_list	*new;

	ret = ft_substr(av, *start, *end-*start);
	// *start = *end;
	new = ft_lstnew(ft_strdup(ret));
	free(ret);
	return (new);
}

void	ms_quotesplit(char *av, int *start, int *end, t_token *token)
{
	while (av[*end])
	{
		if ((av[*end] == ' ' && av[*end -1] != ' ' && \
			token->anchor == NEUTRAL) || av[*end +1] == 0)
		{
			while (av[*start] == ' ')
				(*start)++;
			ft_lstadd_back(&token->entity, ms_tokenrec(av, &*start, &*end));
			*start = *end;
		}
		if (av[*end] == '\'' && token->anchor == NEUTRAL)
			token->anchor = SQUOTE;
		else if (av[*end] == '\'' && token->anchor == SQUOTE)
			token->anchor = NEUTRAL;
		else if (av[*end] == '\"' && token->anchor == NEUTRAL)
			token->anchor = DQUOTE;
		else if (av[*end] == '\"' && token->anchor == DQUOTE)
			token->anchor = NEUTRAL;
		(*end)++;
	}
}

int	ms_split(t_book *record, t_token *token)
{
	int				start;
	int				end;
	char			*av;

	start = 0;
	av = ft_strjoin(record->input, " ");
	while (av[start] == ' ')
				start++;
	end = start;
	ms_quotesplit(av, &start, &end, token);
	if (token->entity && *(char *)(ft_lstlast(token->entity)->content) == 0)
		ft_lstdelone((ft_lstlast(token->entity)), free);
	t_list *ptr = token->entity;
	while (ptr)
	{
		printf("str: %s \n", ptr->content);
		ptr = ptr->next;
	}
	return (0);
}

void	ms_token(t_token *token, t_book *record)
{
	token->anchor = NEUTRAL;
	ms_split(record, token);
	ms_lexer(record, token);
	// token->av = av;
	
}