/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:29:45 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 22:20:28 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	envl_lstdelone(t_env *lst)
{
	if (!lst)
		return ;
	free(lst->var);
	lst->var = NULL;
	free(lst->key);
	lst->key = NULL;
	free(lst->value);
	lst->value = NULL;
	free(lst);
	lst = NULL;
}

void	envl_destroy(t_env **lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		envl_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	env_copy_lstsize(t_env *env_copy)
{
	int		count;

	if (!env_copy)
		return (-1);
	count = 0;
	while (env_copy)
	{
		env_copy = env_copy->next;
		count++;
	}
	return (count);
}

char	*find_in_env(t_env *env_copy, char *key)
{
	if (!env_copy || !key)
		return (NULL);
	while (env_copy)
	{
		if (!ft_strcmp(env_copy->key, key))
			return (env_copy->value);
		env_copy = env_copy->next;
	}
	return (NULL);
}

void	change_value_in_env_copy(t_env *env_copy, char *key, char *value)
{
	if (!env_copy || !key || !value)
		return ;
	while (env_copy)
	{
		if (!ft_strcmp(env_copy->key, key))
		{
			if (env_copy->var)
				free(env_copy->var);
			env_copy->var = ft_strjoin_con(key, "=", value);
			if (env_copy->value)
				free(env_copy->value);
			env_copy->value = ft_strdup(value);
			return ;
		}
		env_copy = env_copy->next;
	}
}
