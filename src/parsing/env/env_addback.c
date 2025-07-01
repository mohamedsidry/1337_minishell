/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:16:03 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:45:53 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void    env_addback(t_env **env_list, t_env *env)
{
    t_env   *tail;

    if (!env_list)
        return ;
    if (!(*env_list))
    {
        *env_list = env;
        return ;
    }
    tail = env_last(*env_list);
    if (tail)
        tail->next = env;
}
