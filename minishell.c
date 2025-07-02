/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:01:02 by msidry            #+#    #+#             */
/*   Updated: 2025/07/02 07:45:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void ll(void);

int	main(int argc, char *argv[], char *env[])
{
	//char	*input;
	t_env	*myenv;
	(void)argc,
	(void)argv,
	//t_commands *cmds;
	myenv = NULL;
	env_manager(&myenv, env, INIT | UPDATE);
	// while (true)
	// {
	// 	  proreadline(&input, &myenv);
	// 	  proaddhistory(input);
	// }
	print_env(myenv);
	env_manager(&myenv, env, DELETE);
	atexit(ll);
	return (0);
}

void ll(void)
{
	system("leaks -q minishell");
}