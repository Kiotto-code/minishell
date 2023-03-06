/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/03/07 01:02:32 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ms_tokenrec(char *av, int *start, int *end)
{
	char	*ret;
	t_list	*new;

	ret = ft_substr(av, *start, *end);
	// printf("start: %d, end: %d", *start, *end);
	printf("str in tokenstr: %s\n", ret);
	// printf("av in tokenstr: %s\n", av);
	// *start = *end;
	new = ft_lstnew(ft_strdup(ret));
	free(ret);
	return (new);
}

int	ms_split(t_book *record, t_token *token)
{
	int				start;
	int				end;
	char			*av;

	start = 0;
	end = 0;
	av = record->input;
	// printf("record->input: %s\n",record->input);
	// token->anchor = NEUTRAL;
	while (av[end])
	{
		if ((av[end] == ' ') && token->anchor == NEUTRAL)
		{
			ft_lstadd_back(&token->entity, ms_tokenrec(av, &start, &end));
			printf("str: %s \n", (char *)(token->entity->content));
			while (av[end] == ' ')
				end++;
			start = end;
		}
		if (av[end] == '\'' && token->anchor == NEUTRAL)
			token->anchor = SQUOTE;
		else if (av[end] == '\'' && token->anchor == SQUOTE)
			token->anchor = NEUTRAL;
		else if (av[end] == '\"' && token->anchor == NEUTRAL)
			token->anchor = DQUOTE;
		else if (av[end] == '\"' && token->anchor == DQUOTE)
			token->anchor = NEUTRAL;
		end++;
	}
	if ((av[end] == 0) && token->anchor == NEUTRAL)
		ft_lstadd_back(&token->entity, ms_tokenrec(av, &start, &end));
	printf ("why%s\n", (token->entity->content));
	return (0);
}

void	ms_token(t_token *token, t_book *record)
{
	token->anchor = NEUTRAL;
	ms_split(record, token);
	// token->av = av;
	
}