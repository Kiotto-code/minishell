/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_interrupt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:30:47 by yichan            #+#    #+#             */
/*   Updated: 2023/04/07 16:18:20 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_interrupt(int sig)
{
	(void)sig;
	write (STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	exit_status = 1;
}

/**
 * @brief SIG_IGN == signal ignored
 * 
 */
void	sigs_interactive_shell(void)
{
	signal(SIGTERM, SIG_IGN);
	signal(SIGINT, &sig_interrupt);
	signal(SIGQUIT, SIG_IGN);
}
