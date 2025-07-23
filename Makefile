# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RLFLAGS     = -lreadline -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include

# Project directories
INC_DIR     = includes
LIBFT_DIR   = libft

# Source files (matched to your exact structure)
CORE        = main.c
CORE_SRC = src/core/signal_handlers.c \

PARSING_SRC = src/parsing/extract_redirections.c \
              src/parsing/parsing.c \
              src/parsing/parse_args.c \
              src/parsing/parse_redirections.c \
              src/parsing/parse_exec.c \
              src/parsing/input_split.c \
              src/parsing/cmd_tree_ops1.c \
              src/parsing/heredoc.c \
              src/parsing/is_builtin.c \
              src/parsing/check_separator.c \
              src/parsing/cmd_tree_ops.c \
              src/parsing/replace_variables.c

MODULES_SRC = src/modules/prompt.c \
              src/modules/free2d.c \
			  src/modules/replace_all_words.c \
              src/modules/env_controls.c \
              src/modules/ft_realloc.c \
              src/modules/replace_word.c \
              src/modules/env_init.c

# Object files
OBJS        = $(CORE_SRC:.c=.o) \
              $(PARSING_SRC:.c=.o) \
              $(MODULES_SRC:.c=.o) \
			  main.o

# Executable name
NAME        = minishell

# Build rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(RLFLAGS) -o $(NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I/opt/homebrew/opt/readline/include -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re