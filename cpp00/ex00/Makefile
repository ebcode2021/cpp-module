# PROGRAM_NAME
NAME = megaphone

# VARIABLE
CC = c++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# COMMAND
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN) ** Compile Done!! ** $(DEFAULT)"

all : $(NAME)
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

clean :
	$(RM) $(OBJS)
	@echo "$(RED) *** Deleteing Objects Done! *** $(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED) *** Delete Program Done! *** $(DEFAULT)"

re :
	make fclean
	make all

.PHONY : all clean fclean re

# COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m