#ifndef MODULES_H
# define MODULES_H

# include "../libft/libft.h"

typedef struct env_vars {
    char            *name;
    char            *value;
    int             hide;
    struct env_vars *next;
} t_env;

char    *replace_word(char *str, char *w0, char *w1, int usefree);
void    free2d(void **ptr);
char    *get_work_dir(void);
char    *replace_all_words(char *str, char *w0, char *w1, int usefree);
t_env   *add_env(t_env *head, char *name, char *value);

/* Global environment list */
extern t_env    *g_env;

/* Core Environment Functions */
void    env_init(int argc, char **argv, char **env);
char    *fetch(char *var_name);
void    destroy_all_env(t_env *head);

#endif