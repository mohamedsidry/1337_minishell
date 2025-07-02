/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettersetter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 07:20:18 by msidry            #+#    #+#             */
/*   Updated: 2025/07/02 08:24:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"


void set_env_value(t_env *env, char *key, char *value)
{
    t_env *target;

    target = env_find(env, key);
    if (!key)
        return ;
    free(target->value);
    target->value = value;
}

char *get_env_value(t_env *env, char *key)
{
    t_env *target;

    target = env_find(env, key);
    if (!target)
        return (NULL);
    return  (target->value);
}