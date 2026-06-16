NAME = libftprintf.a\

SOURCES = ft_printf.c\
		  ft_putstr.c\
		  ft_putchar.c\
		  ft_putnbrs.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJECTS)
	@echo "Compiling...."
	@$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

clean: 
	@echo "Cleaning...."
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
