/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:57:22 by msidry            #+#    #+#             */
/*   Updated: 2025/06/30 23:02:38 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum e_visibility
{
	hidden,
	visible,
}	t_visibility;

typedef struct s_env
{
	char			*key;
	char			*value;
	t_visibility	visibility;
	struct s_env	*next;
}	t_env;

typedef enum e_task
{
	INIT,
	RESET,
}	t_task;

#endif // TYPEDEF_H