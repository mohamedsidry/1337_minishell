/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:22:32 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:46:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void env_delete(t_env *envnode)
{
    if (!envnode)
        return ;
    free(envnode->key);
    free(envnode->value);
    free(envnode);
}