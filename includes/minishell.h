/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:17:57 by yichan            #+#    #+#             */
/*   Updated: 2023/04/07 19:28:43 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h> //pid_t data type
# include <sys/errno.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/includes/libft.h"

# define DEFAULT	"\033[0m"
# define CYAN		"\033[0;36m"
# define RED		"\033[0;31m"

# define CLOSE		"\001\033[0m\002"
# define BOLD		"\001\033[1m\002"
# define BEGIN(x,y)	"\001\033["#x";"#y"m\002"

# define SQUOTE		1
# define DQUOTE		2
# define DOLLAR		3
# define NEUTRAL	0

# define PIPE		4
# define QUERY		5
// # define DOLLAR		6
# define LEFT		7
# define RIGHT		8
# define LITERAL	9

int	exit_status;

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;

}	t_env;

//lexer
typedef struct s_token
{
	char	*entity;
	int		type;
}	t_token;

typedef struct s_book
{
	char	**env_arr;
	char	*input;
	int		anchor;
	t_list	*env;
	t_list	*token;
}	t_book;

typedef struct s_cmdl
{
	char			**command;
	int				in;
	int				out;
	int				pipe_fd[2];
	int				fork;
	pid_t			pid;
	struct s_rdr	*redir;
	struct s_cmdl	*next;
}				t_cmdl;

//----utils
//ms_libft.c

//----allocate
//ms_initiate.c
void	ms_token(t_book *record);
int		ms_inputloop(t_book *record);
void	record_init(t_book *record, char **envp);
// ms_lexer.c
int		ms_lexer(t_book *record);
//-----signals
// sig_interactive.c
void	sigs_interactive_shell(void);
// sig_non_interactive.c
void	sigs_non_interactive_shell(void);


#endif
