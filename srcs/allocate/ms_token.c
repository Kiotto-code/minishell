/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/03/05 23:21:36 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_tokenrec(char *av, int *start, int *end)
{
	char	*ret;

	ret = ft_substr(av, *start, *end -1);
	*start = *end;
	return (ret);
}

char	**ms_split(t_book *record, t_token *token)
{
	int				start;
	int				end;
	char			*av;

	start = 0;
	end = start;
	av = record->input;
	while (av[end])
	{
		end = start;
		if (av[end] == ' ' && token->anchor == NEUTRAL)
				token->entity->content = ms_tokenrec(av, &start, &end);
		if (av[end] == '\'' && token->anchor == NEUTRAL)
			token->anchor = SQUOTE;
		else if (av[end] == '\'' && token->anchor == SQUOTE)
			token->anchor = NEUTRAL;
		else if (av[end] == '\"' && token->anchor == NEUTRAL)
			token->anchor = DQUOTE;
		else if (av[end] == '\"' && token->anchor == DQUOTE)
			token->anchor = NEUTRAL;
		else if (av[end] == '$' && token->anchor != SQUOTE)
			token->dollar = 1;
		end++;
	}

}

void	ms_token(t_token *token, t_book *record)
{
	ms_split(record, token)
	// token->av = av;
	
}