/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:54:38 by okamili           #+#    #+#             */
/*   Updated: 2025/07/22 21:35:16 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modules.h"

t_env	*g_env;

t_env	*last_env(t_env *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

t_env	*find_env(t_env *head, char *name)
{
	while (head)
	{
		if (ft_strlen(head->name) == ft_strlen(name)
			&& !ft_strncmp(head->name, name, ft_strlen(name)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_env	*add_env(t_env *head, char *name, char *value)
{
	t_env	*new;
	t_env	*tmp;

	if (!name)
		return (head);
	tmp = find_env(head, name);
	if (tmp)
	{
		if (value)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			tmp->hide = 0;
		}
		return (head);
	}
	new = ft_calloc(1, sizeof(t_env));
	new->name = ft_strdup(name);
	if (value)
		new->value = ft_strdup(value);
	tmp = last_env(head);
	if (!tmp)
		return (new);
	tmp->next = new;
	return (head);
}

void destroy_all_env(t_env *head)
{
    t_env *tmp;
    
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->name);
        free(tmp->value);
        free(tmp);
    }
}

char	*fetch(char *var_name)
{
	t_env			*tmp;

	tmp = find_env(g_env, var_name);
	if (tmp)
		return (tmp->value);
	return (getenv(var_name));
}
