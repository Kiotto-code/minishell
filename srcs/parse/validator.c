/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:23:33 by yichan            #+#    #+#             */
/*   Updated: 2023/04/09 17:23:35 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_check(char *input, int it)
{
	if (input[it] == '|' && input[it + 1] == '|')
		return (print_msg(1, "syntax error near unexpected token `||'", 258));
	if (input[it] == '|')
		return (print_msg(1, "syntax error near unexpected token `|'", 258));
	if (input[it] == ';' && input[it + 1] == ';')
		return (print_msg(1, "syntax error near unexpected token `;;'", 258));
	if (input[it] == ';')
		return (print_msg(1, "syntax error near unexpected token `;'", 258));
	return (0);
}

int	counting_quotes(char *input, int *it, char quote)
{
	while (input[++(*it)])
	{
		if (input[*it] == quote)
			return (0);
	}
	return (print_msg(1, "syntax error with unclosed quotes", 258));
}

int	counting_pipes_or_delimeters(char *input, int it)
{
	it = pass_whitespaces(input, it);
	if (input[it] == '|')
	{
		if (input[it + 1] == '|')
			return (print_msg(1, \
				"syntax error near unexpected token `||'", 258));
		return (print_msg(1, "syntax error near unexpected token `|'", 258));
	}
	if (input[it] == ';')
	{
		if (input[it + 1] == ';' || input[it - 1] == ';')
			return (print_msg(1, \
				"syntax error near unexpected token `;;'", 258));
		return (print_msg(1, "syntax error near unexpected token `;'", 258));
	}
	return (0);
}

int	validator(char *input)
{
	int	it;

	if (!input)
		return (1);
	it = pass_whitespaces(input, 0);
	if (input[it] == '|' || input[it] == ';')
		return (first_check(input, it));
	while (input[it])
	{
		if ((input[it] == '|' || input[it] == ';') && \
				counting_pipes_or_delimeters(input, it + 1))
			return (1);
		if (input[it] == '\'' && counting_quotes(input, &it, input[it]))
			return (1);
		if (input[it] == '\"' && counting_quotes(input, &it, input[it]))
			return (1);
		if ((input[it] == '<' || input[it] == '>') && \
				counting_redirect(input, &it, input[it]))
			return (1);
		it++;
	}
	return (0);
}
