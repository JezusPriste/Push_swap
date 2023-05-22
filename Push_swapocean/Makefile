NAME = push_swap

OUTPUT = push_swap.a

HEADER = $(NAME:.a=.h)

SOURCES = 	error_free.c \
			ft_split.c \
			ft_substr.c \
			main.c \
			push_command.c \
			push_swap_init.c \
			push_swap_utils.c \
			push_swap.c \
			push.c \
			reverse_rotate_command.c \
			rotate_command.c \
			stack_init.c \
			stack_utils.c \
			swap.c \
			tiny_sort.c \
		

			
OBJ = $(SOURCES:.c=.o)

LIBC = ar -rcs

CC = gcc

RM = rm -f

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OUTPUT)
		$(CC) $< -o $@

$(OUTPUT): $(OBJ)
		$(LIBC) $(OUTPUT) $^

%.o:%.c
		@$(CC) -Wall -Wextra -g -O2 -c $< -o $@
		@echo "\033[36mCompiled Ok!\033[0m"
		
clean:
		@$(RM) $(OBJ) $(OUTPUT)
		@echo "\033[35mAll Cleaned^^\033[0m"

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re