#ifndef PARSING_H
# define PARSING_H

# include <sys/stat.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "modules.h"

typedef struct cmd_data {
    char            *cmd;           // Original command
    char            *exec;          // Executable path
    char            **args;         // Command arguments
    char            **redir_files;  // Redirection files
    char            **redir_sym;    // Redirection symbols
    char            *sep;           // Separator (| or ;)
    char            *heredoc_data;  // Heredoc content
    int             error;          // Command error
    int             prev_error;     // Previous command error
    pid_t           process_id;     // Process ID
    struct cmd_data *next;          // Next command
} t_cmd;

/* Command Tree Operations */
t_cmd   *allocate_cmd_node(char *whole_command);
t_cmd   *last_cmd_node(t_cmd *head);
t_cmd   *append_cmd_to_tree(t_cmd *head, t_cmd *new_command);
t_cmd   *remove_cmd_from_tree(t_cmd *head, t_cmd *todelete);
void    erase_cmd_node(t_cmd *cmd_pointer);

/* Parsing Functions */
int     check_separator(t_cmd *cmd);
int     check_quotes(t_cmd *cmds);
int     parse_redir(t_cmd *cmd);
void    manage_heredoc(t_cmd *cmds);

char    *clean_quotes(char *cmd);
char    *replace_variables(char *str, int err);
char    **parse_args(char *cmd);
int     is_builtin(char *exec);
char    *parse_exec(char *cmd, int *err);
void    parsing(t_cmd *cmd);

char    **extract_redir(char *cmd);
int     parse_redir(t_cmd *cmd);

/* Command Tree Management */
t_cmd   *input_split(char *input, int *err);
void    parsing(t_cmd *cmd);
t_cmd   *get_next_cmd(t_cmd *head, int *err);
void    free_cmd_tree(t_cmd *head);

#endif