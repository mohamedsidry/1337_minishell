
# Output executable name

NAME = minishell

# Compiling flags

CC = cc
CFLAGS = -Wall -Werror -Wextra
CSTAGE = -c

# Cleaning flags

RM = rm
RMFLAGS = -fr



# Sources Includes and Depandencies .

MAIN 	=	minishell.c
UTILS 	=	src/utils/getkey.c src/utils/getvalue.c
PARSING =	src/parsing/env/env_addback.c src/parsing/env/env_clear.c \
			src/parsing/env/env_create.c src/parsing/env/env_delete.c \
			src/parsing/env/env_find.c src/parsing/env/env_last.c \
			src/parsing/env/env_manager.c \
			src/parsing/env/gettersetter.c
TEST 	= 	test/env/print_env.c
SRCS = $(MAIN) $(UTILS) $(PARSING) $(TEST)

INCLUDES =	include/minishell.h include/const.h include/error.h \
			include/test.h include/typedef.h \
			src/utils/utils.h \
			src/parsing/parsing.h 

# LIBFT 

LIBFTARC	= libs/libft/libft.a
LIBFTPATH	= libs/libft/
LIBFT = libft


# LIB FOR READLINE and addhitory functions !

DEPLIB = -lreadline


OBJS = $(SRCS:.c=.o)

%.o:%.c $(INCLUDES)
	@echo "\033[1;33m⚙️​ compiling :\033[0m\033[0;35m $< \033[0m"
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

$(NAME): $(LIBFTARC) $(OBJS)
	@echo "\033[1;33m​🔗​​linking   :\033[0m\033[0;35m $@ \033[0m"
	@$(CC) $(CFLAGS) $(DEPLIB) -L$(LIBFTPATH) $(LIBFTARC) -I$(LIBFTPATH) $(OBJS) -o $@
	@echo "\033[1;33m🚀$(NAME) : \033[0mbuilding finished !"


clean:
	@$(RM) $(RMFLAGS) $(OBJS)
	@make -C $(LIBFTPATH) clean

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@make -C $(LIBFTPATH) fclean
re: fclean all


all: $(NAME)

$(LIBFTARC) :
	@make -C $(LIBFTPATH)


.PHONY: clean fclean re all debug run norms $(LIBFT)

run: $(NAME) clean
	@./$(NAME)

debug:  
	@make run DEBUGMODE=1 SANITIZER=1 TESTUNIT=1

fvrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

vrun: clean $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)


norms:
	@echo $(CHECKINGNORMS)
	@norminette | grep 'Error!' && echo $(KO) || echo $(OK)

CHECKINGNORMS = "\033[1;33mNorminette ...\033[0m"


OK="\033[1;32mNorminette OK!\033[0m"
KO="\033[1;31mNorminette KO!\033[0m"