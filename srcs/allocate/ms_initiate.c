/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:40:48 by yichan            #+#    #+#             */
/*   Updated: 2023/02/24 14:37:31 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	record_init(t_book *record, char **envp)
{
	record->env_arr = ft_duparr(envp);
	record->env = ft_arr2lst
}