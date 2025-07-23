#include <stdio.h>        // For printf()
#include <stdlib.h>       // For free()
#include <string.h>       // For strlen()
#include <readline/readline.h>
#include <readline/history.h>
#include "core.h"
#include "modules.h"
#include "parsing.h"      // This contains t_cmd definition and function prototypes

void print_cmd_tree(t_cmd *cmds)
{
    int cmd_num = 1;
    
    while (cmds)
    {
        printf("─── Command %d ───\n", cmd_num++);
        printf("Exec: %s\n", cmds->exec);
        
        printf("Args: ");
        for (int i = 0; cmds->args[i]; i++)
            printf("[%s] ", cmds->args[i]);
        printf("\n");
        
        if (cmds->redir_sym)
        {
            printf("Redirections:\n");
            for (int i = 0; cmds->redir_sym[i]; i++)
                printf("  %s %s\n", cmds->redir_sym[i], cmds->redir_files[i]);
        }
        
        if (cmds->heredoc_data)
            printf("Heredoc: [%s]\n", cmds->heredoc_data);
        
        cmds = cmds->next;
    }
}

int main(int argc, char **argv, char **env)
{
    char *input;
    t_cmd *cmds;
    int err = 0;

    env_init(argc, argv, env);
    
    while (1)
    {
        input = readline("parser_test$ ");
        if (!input) break;
        
        if (strlen(input) > 0)
            add_history(input);
        
        cmds = input_split(input, &err);
        free(input);
        
        if (cmds)
        {
            parsing(cmds);
            print_cmd_tree(cmds);
            free_cmd_tree(cmds);
        }
        else if (err)
        {
            printf("Parser error: %d\n", err);
        }
    }
    
    destroy_all_env(g_env);
    return 0;
}