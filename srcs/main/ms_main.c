/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:16:14 by yichan            #+#    #+#             */
/*   Updated: 2023/02/25 00:59:47 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_book	record;

	(void)av;
	// int	i = 0;
	// int len = ft_arrind(env);
	// while (i < len)
	// 	printf("%s\n", env[i++]);
	if (ac != 1)
	{
		ft_putstr_fd("Minishell Initiate cannot have argument \n", 1);
		return (EXIT_FAILURE);
	}
	record_init(&record, env);
}