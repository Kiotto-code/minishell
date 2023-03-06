/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:48 by yichan            #+#    #+#             */
/*   Updated: 2023/03/06 23:42:37 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*newenvl(char *content)
{
	t_env	*node;

	node = ft_calloc(sizeof(t_env));
	if (!node)
		return (0);
	node->var = content;
	node->next = 0;
	return (node);
}

int	ft_arr2envl(t_list **lst, char **arr)
{
	int	i;
	int	arr_len;

	if (!lst || !arr)
		return (0);
	i = -1;
	arr_len = ft_arrind(arr);
	while (++i < arr_len)
	{
		ft_lstadd_back(lst, ft_lstnew(newenvl(arr[i])));
		// (*lst)->content = (t_env *)((*lst)->content);
	}
	// printf ("%s \n", ((t_env *)(*lst)->content)->var);
	return (0);
}

int	name_expand(t_list **lst, char **arr)
{
	t_list	*lst_itr;
	t_env	*env;

	if (!lst || !arr)
		return (0);
	lst_itr = (*lst);
	while ((lst_itr))
	{
		env = lst_itr->content;
		env->value = ft_strchr(env->var, '=');
		env->key = ft_substr(env->var, 0, env->value - env->var);
		(lst_itr) = (lst_itr)->next;
	}
	printf ("%s \n", ((t_env *)(*lst)->content)->var);
	return (0);
}

// pid_t	file_open(char *path, char *flag)

void	record_init(t_book *record, char **envp)
{
	// record->env_arr = ft_duparr(envp);
	record->env = 0;
	record->token = 0;
	ft_arr2envl(&(record->env), envp);
	name_expand(&(record->env), envp);
	
	// record->mininput = open(path, _CREAT | 
	// printf("%d\n", ft_lstsize(record->env));
	// printf("%d\n", ft_arrind(envp));
	
	// printf("%s\n", record->env->var);
	// printf("%s\n", record->env->expand);
}