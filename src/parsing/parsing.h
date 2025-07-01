/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:04:01 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:43:31 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

void    env_manager(t_env **myenv, char *env[], t_task task);

t_env   *env_create(char *key, char *value, t_visibility visibility);
void    env_addback(t_env **env_list, t_env *env);
void    env_delete(t_env *envnode);
void    env_clear(t_env **env);
t_env   *env_last(t_env *env);
t_env   *env_find(t_env *env, char *key);

#endif // PARSING_H