/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:30:30 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 22:35:56 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shlvl_down(t_book *mini)
{
	char	*cur_lvl;
	char	*up_lvl;

	cur_lvl = find_in_env(mini->env, "SHLVL");
	up_lvl = ft_itoa(ft_atoi(cur_lvl) - 1);
	change_value_in_env_copy(mini->env, "SHLVL", up_lvl);
	free(up_lvl);
}

void	shlvl_up(t_book *mini)
{
	char	*cur_lvl;
	char	*up_lvl;

	cur_lvl = find_in_env(mini->env, "SHLVL");
	up_lvl = ft_itoa(ft_atoi(cur_lvl) + 1);
	change_value_in_env_copy(mini->env, "SHLVL", up_lvl);
	free(up_lvl);
}
