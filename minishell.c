/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:01:02 by msidry            #+#    #+#             */
/*   Updated: 2025/07/01 00:57:43 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	//char	*input;
	t_env	*myenv;
	(void)argc,
	(void)argv,
	//t_commands *cmds;
	env = NULL;
	env_manager(&myenv, env, INIT);
	print_env(myenv);
	return (0);
}
