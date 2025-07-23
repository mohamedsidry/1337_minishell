#include "../includes/core.h"

void sig_handler(int sign)
{
    if (sign == SIGINT)
    {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}