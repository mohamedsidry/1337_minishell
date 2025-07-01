/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:35:08 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:50:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env *env_find(t_env *env, char *key)
{
    if (!env || !key)
        return (NULL);
    while (env)
    {
        if ((ft_strlen(key) == ft_strlen(env->key)) && 
            !ft_strncmp(env->key, key, ft_strlen(key)))
            return (env);
        env = env->next;
    }
    return (NULL);
}