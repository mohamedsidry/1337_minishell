/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasszgh <anasszgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:40:21 by okamili           #+#    #+#             */
/*   Updated: 2025/07/22 21:45:39 by anasszgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"  // Must be first
#include "../includes/modules.h"
#include "../libft/libft.h"
#include <stdbool.h>

static bool is_separator(char *str)
{
    if (ft_strncmp(str, "||", 2) == 0) return true;
    if (ft_strncmp(str, "&&", 2) == 0) return true;
    if (*str == '|' || *str == ';') return true;
    return false;
}


static int	check_quotes_loop(char *str)
{
	int	dquotes;
	int	squotes;

	dquotes = 0;
	squotes = 0;
	while (str[0])
	{
		dquotes += (!(squotes & 1) && str[0] == '"');
		squotes += (!(dquotes & 1) && str[0] == '\'');
		str++;
	}
	return ((squotes & 1) || (dquotes & 1));
}

int	check_quotes(t_cmd *cmds)
{
	while (cmds)
	{
		if (check_quotes_loop(cmds->cmd))
		{
			ft_putstr_fd("Minishell: syntax error: Missing closing quote.\n", 2);
			return (1);
		}
		cmds = cmds->next;
	}
	return (0);
}

static int	command_length(char *str)
{
	int	length;
	int	dquotes;
	int	squotes;

	length = 0;
	dquotes = 0;
	squotes = 0;
	while (str[0])
	{
		length++;
		if (ft_strchr(";|", str[0]) && (!(dquotes & 1) && !(squotes & 1)))
			return (length);
		dquotes += (!(squotes & 1) && str[0] == '"');
		squotes += (!(dquotes & 1) && str[0] == '\'');
		str++;
	}
	return (length);
}

t_cmd *input_split(char *input, int *err)
{
    t_cmd *result = NULL;
    char *start = input;
    char *end = input;
    
    while (*end)
    {
        // Skip whitespace
        while (*end && ft_isspace(*end))
            end++;
        start = end;
        
        // Find end of command
        while (*end && !is_separator(end))
            end++;
            
        // Create command node if we found text
        if (end > start)
        {
            char *cmd_str = ft_substr(start, 0, end - start);
            result = append_cmd_to_tree(result, 
                     allocate_cmd_node(ft_strtrim(cmd_str, " \t")));
            free(cmd_str);
        }
        
        // Handle separator
        if (is_separator(end))
        {
            char sep[3] = {*end, 0};
            if (*end == *(end+1)) // Handle && and ||
                sep[1] = *end++;
            last_cmd_node(result)->sep = ft_strdup(sep);
            end++;
        }
    }
    return result;
}
