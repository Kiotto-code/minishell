/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:17:57 by yichan            #+#    #+#             */
/*   Updated: 2023/03/05 00:30:34 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/includes/libft.h"

typedef struct s_env
{
	char *var;
	char *key;
	char *value;
	struct s_env *next;
	struct s_env *prev;
}	t_env;

typedef struct s_token
{
	char **token;
	char *cmd;
	char **flag;
	struct s_token *next;
	struct s_token *prev;
}	t_token;

typedef struct s_book
{
	char	**env_arr;
	char	*input;
	t_list	*env;
	t_list	*token;
}	t_book;

//----utils
//ms_libft.c

//----allocate
//ms_initiate.c
int		ms_inputloop(t_book *record);
void	record_init(t_book *record, char **envp);


#endif