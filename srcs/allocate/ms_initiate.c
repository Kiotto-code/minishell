/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:48 by yichan            #+#    #+#             */
/*   Updated: 2023/03/03 19:13:45 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	name_expand(t_list **lst, char **arr)
{
	int	i;
	int	arr_len;
	t_list *ptr;

	if (!lst || !arr)
		return (0);
	ptr = (*lst);
	i = -1;
	arr_len = ft_lstsize(ptr);
	while (++i < arr_len)
	{
		(ptr)->var = ft_split((ptr)->content, '=')[0];
		// printf("here%s\n", (ptr)->var);
		(ptr)->expand = ft_strchr((ptr)->content, '=') +1;
		if ((ptr)->next)
			(ptr) = (ptr)->next;
	}
	return (0);
}

void	record_init(t_book *record, char **envp)
{
	// record->env_arr = ft_duparr(envp);
	record->env = 0;
	ft_arr2lst(&(record->env), envp, &ft_lstadd_back);
	// printf("%d\n", ft_lstsize(record->env));
	// printf("%d\n", ft_arrind(envp));
	name_expand(&(record->env), envp);
	
	printf("%s\n", record->env->var);
	printf("%s\n", record->env->expand);
}