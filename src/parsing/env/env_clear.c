/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:25:25 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:45:57 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"


void env_clear(t_env **env)
{
    t_env   *tmp;
    t_env   *current;

    
    if (!env || !(*env))
        return ;
    current = *env;
    while (current)
    {
        tmp = current->next;
        env_delete(current);
        current = tmp;
    }
    *env = NULL;
}