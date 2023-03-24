/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:19:09 by yichan            #+#    #+#             */
/*   Updated: 2023/03/24 20:11:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief record token into a string and lexer its type(havent done).
 * @param av (the whole argument from readline output)
 * @param start (Where to begin)
 * @param end (Where to end)
 * @return t_token* 
 */

t_token	*ms_tokenrec(char *av, int *start, int *end)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token));
	if (!new)
		return (0);
	while(av)
	ft_lstadd_back(&record->token,
				ft_lstnew(ms_tokenrec(av, &start, &end)));
	new->entity = ft_substr(av, *start, (*end) - (*start));
	new->type = 0;
	return (new);
}


void	check_anchor(char c, t_book *record)
{
	if (c == '\'' && record->anchor == NEUTRAL)
		record->anchor = SQUOTE;
	else if (c == '\'' && record->anchor == SQUOTE)
		record->anchor = NEUTRAL;
	else if (c == '\"' && record->anchor == NEUTRAL)
		record->anchor = DQUOTE;
	else if (c == '\"' && record->anchor == DQUOTE)
		record->anchor = NEUTRAL;
}

/**
 * @brief It is to record a token based on spaces other than those within quotaion.
 * 
 * @param record The t_book struct which contain the token t_list and anchor required.
 */
void	ms_quotesplit(t_book *record)
{
	int				start;
	int				end;
	char			*av;

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
			ft_lstadd_back(&record->token,
				ft_lstnew(ms_tokenrec(av, &start, &end)));
			start = end;
		}
		check_anchor(av[end], record);
		end++;
	}
}

/**
 * @brief Split the input into 
 * 
 * @param record 
 * @return int 
 */
void	ms_token(t_book *record)
{
	t_token	*itr;

	ms_quotesplit(record);
	// printf("sdad");
	itr = (t_token *)(record->token->content);
	printf("str: %s \n", itr->entity);
}
