#ifndef CORE_H
# define CORE_H

/* Standard Library Headers */
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "parsing.h"
# include "modules.h"

/* Project Constants */
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/* Signal Handler */
void    sig_handler(int sign);

/* Environment Cleanup */
void    destroy_all_env(t_env *head);

/* Execution Functions */
void    run_commands(t_cmd *cmd);
t_cmd   *run_pipe_commands(t_cmd *head, int *err);
void    close_prgm(t_cmd *cmds);

#endif