/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:29:29 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 21:13:08 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*args_lstnew(char *arg_str, t_book *mini)
{
	t_token	*element;

	(void)mini;
	element = (t_token *)malloc(sizeof(t_token));
	if (!element)
		return (NULL);
	element->entity = ft_strdup(arg_str);
	element->redirect = 0;
	element->next = NULL;
	free(arg_str);
	return (element);
}

void	args_lstadd_back(t_token	**list, t_token *new)
{
	t_token	*last;

	if (!list || !new)
		exit(EXIT_FAILURE);
	if (*list)
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*list = new;
}

void	args_lstdelnode(t_token **args)
{
	t_token	*next;

	if (!args || !(*args))
		return ;
	next = (*args)->next;
	free((*args)->entity);
	(*args)->entity = NULL;
	free((*args));
	*args = next;
}

void	args_lstdelone(t_token *lst)
{
	if (!lst)
		return ;
	free(lst->entity);
	lst->entity = NULL;
	free(lst);
	lst = NULL;
}

void	args_destroy(t_token **lst)
{
	t_token	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		args_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
