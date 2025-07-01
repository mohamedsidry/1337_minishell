/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:40:17 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 08:43:30 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void print_env(t_env *env)
{
    
    if (!env)
    {
        printf("Empty env list\n");
        return ;
    }
    while (env)
    {
        //printf("key   : %s\n", env->key);
        //printf("value : %s\n", env->value);
        //if (env->visibility == visible)
        //    printf("visibility : visible\n");
        //else
        //    printf("visibility : hidden\n");
        printf("%s=%s\n", env->key, env->value);
        env = env->next;
    }
}