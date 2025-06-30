
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

MAIN = minishell.c
SRCS = $(MAIN)

vpath %.h include
INCLUDES = header.h const.h error.h  test.h typedef.h utils.h

# LIB FOR READLINE and addhitory functions !

DEPLIB = -lreadline


OBJS = $(SRCS:.c=.o)

%.o:%.c $(INCLUDES)
	@echo "\033[1;33m⚙️​ compiling :\033[0m\033[0;35m $< \033[0m"
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

$(NAME): $(OBJS)
	@echo "\033[1;33m​🔗​​linking   :\033[0m\033[0;35m $@ \033[0m"
	@$(CC) $(CFLAGS) $(DEPLIB) $(OBJS) -o $@
	@echo "\033[1;33m🚀$(NAME) : \033[0mbuilding finished !"


clean:
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all


all: $(NAME)

.PHONY: clean fclean re all debug run norms

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