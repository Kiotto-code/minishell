/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:17:57 by yichan            #+#    #+#             */
/*   Updated: 2023/04/18 22:37:06 by yichan           ###   ########.fr       */
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
# define DLEFT		10
# define DRIGHT		11

int	exit_status;

//envl
typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

//argl
typedef struct s_token
{
	char	*entity;
	int		type;
	int		redirect;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

//cmdl
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

//argl
// typedef struct s_argl
// {
// 	char			*arg_origin;
// 	int				redirect;
// 	struct s_argl	*next;
// }				t_argl;

//shell
typedef struct s_book
{
	char	**env_arr;
	char	*input;
	int		anchor;
	t_env	*env;
	// t_token	*token;
	t_cmdl	*cmds;
	t_token	*args;
}	t_book;

typedef struct s_redir
{
	char			*type;
	char			*name;
	struct s_redir	*next;
}				t_redir;


//----execution
//execute_cmds.c
void	execute_cmds(t_book *mini, t_cmdl *cmds);
//here_doc.c
void	heredoc_processing(t_cmdl *cmd);
int		heredoc_checking(t_cmdl *cmd);
//path_processing.c
char	*path_processing(t_book *mini, char *line);
//pipex.c
int	pipe_creator(t_cmdl *cmds);
// builtin.c
int	builtin_checker(char *command);

//----lexer
// ms_lexer.c
int		ms_lexer(t_book *record);

//----parse
//parser_utils.c
int	pass_whitespaces(char *input, int it);
void	fd_opening(t_cmdl *cmds);
//redirect_processing.c
t_redir	*redirect_processing(t_token **args);
//validator.c
int	validator(char *input);
int	counting_redirect(char *input, int *it, char redirect);

//-----signals
// sig_interactive.c
void	sigs_interactive_shell(void);
// sig_non_interactive.c
void	sigs_non_interactive_shell(void);

//-----token
// ms_envp2.c
void	ms_envladd_back(t_env **lst, t_env *new);
t_env	*newenvl(char *content);
t_env	*ft_envllast(t_env *lst);
// ms_token2.c
void	ms_tokenladd_back(t_token **lst, t_token *new);
t_token	*ft_tokenllast(t_token *lst);
//ms_token.c
void	ms_token(t_book *record);
int		ms_inputloop(t_book *record);
void	record_init(t_book *record, char **envp);


//----utils
//argument_utils.c
void	args_lstdelnode(t_token **args);
void	args_destroy(t_token **lst);
//env_utils.c
int	env_copy_lstsize(t_env *env_copy);
char	*find_in_env(t_env *env_copy, char *key);
void	change_value_in_env_copy(t_env *env_copy, char *key, char *value);
//execute_utils.c
int	execute_dup2(t_cmdl *cmds);
// memory_processing.c
void	array_liberator(char **array);
void	liberator(t_book *mini);;
// command_utils.c
void	cmds_destroy(t_cmdl **lst);



/*
 * //only for printing; No particular usage
 */
void	print_env_copy(t_env *env_copy);
void	print_args(t_token *args);
void	print_cmds(t_cmdl *cmds);
void	print_redir(t_cmdl *cmds);
int		print_msg(int ret_val, char *message, int ext_stat);
void	no_such_message(char *message);
void	error_msg(char *message);


#endif
