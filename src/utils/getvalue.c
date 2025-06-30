/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:13:10 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:55:20 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char *getvalue(char *str, int sep)
{
    char *target;
    char *key;

    if (!str)
        return (NULL);
    target = ft_strchr(str, sep);
    if (!target)
        return (NULL);
    key = ft_substr(target + 1, 0, ft_strlen(target));
    return (key);
}