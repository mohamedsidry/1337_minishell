/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:52:00 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 08:40:55 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void init_env(t_env **myenv, char *env[]);
static void rest_env(t_env **myenv);

void    env_manager(t_env **myenv, char *env[], t_task task)
{
    if (task == INIT)
        init_env(myenv, env);
    if (task == RESET)
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
    printf("i was hererererer !\n");
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