/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:01:34 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:46:42 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env *env_create(char *key, char *value, t_visibility visibility)
{
    t_env   *node;

    node = ft_calloc(1, sizeof(t_env));
    if (!node)
        return (NULL);
    node->key = ft_strdup(key);
    node->value = ft_strdup(value);
    node->visibility = visibility;
    if (!node->key || !node->value)
    {
        free(node->key);
        free(node->value);
        free(node);
        return (NULL);
    }
    return (node);
}
