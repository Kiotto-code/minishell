/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:29:29 by yichan            #+#    #+#             */
/*   Updated: 2023/04/09 16:41:18 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_argl	*args_lstnew(char *arg_str, t_book *mini)
{
	t_argl	*element;

	(void)mini;
	element = (t_argl *)malloc(sizeof(t_argl));
	if (!element)
		return (NULL);
	element->arg_origin = ft_strdup(arg_str);
	element->redirect = 0;
	element->next = NULL;
	free(arg_str);
	return (element);
}

void	args_lstadd_back(t_argl	**list, t_argl *new)
{
	t_argl	*last;

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

void	args_lstdelnode(t_argl **args)
{
	t_argl	*next;

	if (!args || !(*args))
		return ;
	next = (*args)->next;
	free((*args)->arg_origin);
	(*args)->arg_origin = NULL;
	free((*args));
	*args = next;
}

void	args_lstdelone(t_argl *lst)
{
	if (!lst)
		return ;
	free(lst->arg_origin);
	lst->arg_origin = NULL;
	free(lst);
	lst = NULL;
}

void	args_destroy(t_argl **lst)
{
	t_argl	*tmp;

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
