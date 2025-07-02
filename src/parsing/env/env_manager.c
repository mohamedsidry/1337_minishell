/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:52:00 by msidry            #+#    #+#             */
/*   Updated: 2025/07/02 08:25:47 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void init_env(t_env **myenv, char *env[]);
static void rest_env(t_env **myenv);
static void update_env(t_env *myenv);

void    env_manager(t_env **myenv, char *env[], t_task task)
{
    if (task & INIT)
        init_env(myenv, env);
    if (task & UPDATE)
        update_env(*myenv);
    if (task & DELETE)
        rest_env(myenv);
}


static void init_env(t_env **myenv, char *env[])
{
    size_t  idx;
    char    *key;
    char    *value;
    t_env   *envnode;

    idx = 0;
    if (!env)
        return;
    while (env[idx])
    {
        key = getkey(env[idx], '=');
        value = getvalue(env[idx], '=');
        envnode = env_create(key, value, visible);
        if (!envnode)
        {
            env_clear(myenv);
            free(key);
            free(value);
            //exit(1);
        }
        env_addback(myenv, envnode);
        free(key);
        free(value);
        idx++;
    }
}

static void rest_env(t_env **myenv)
{
    env_clear(myenv);
}

static void update_env(t_env *myenv)
{
    char *lvl = NULL;
    char *path= NULL;
    char *cwd;
    char *path1;

    if (!myenv)
        return ;
    lvl = get_env_value(myenv, "SHLVL");
    if (lvl)
        set_env_value(myenv, "SHLVL", ft_itoa(ft_atoi(lvl) + 1));
    path = get_env_value(myenv, "PATH");
    path1 = ft_strjoin(path, ":");
    cwd = getcwd(NULL, -42);
    if (path)
        set_env_value(myenv, "PATH", ft_strjoin(path1, cwd));
    set_env_value(myenv, "SHELL", ft_strdup(get_env_value(myenv, "_")));
    free(path1);
    free(cwd);
}
