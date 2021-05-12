##
## ETNA PROJECT, 29/10/2020 by yu_t
## [...]
## File description:
##      [...]

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -g3

CFLAGS	+=	-I ./include

RM		=	rm -f

NAME	= 	my_crd

SRC		=  	src/my_puts.c \
			src/my_getnbr.c \
			src/my_readline.c \
			src/my_lists.c \
			src/my_strops.c \
			src/my_str_to_word_array.c \
			src/commands.c \
			src/main.c

OBJS	=	$(SRC:.c=.o)

%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m] %99s\n" $< | tr ' ' '.'

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] %102s\n" $(NAME) | tr ' ' '.'

clean :
	@$(RM) $(OBJS)
	@printf "[\033[0;31mdeleted\033[0m] %100s\n" $(OBJS) | tr ' ' '.'

fclean : clean
	@$(RM) $(NAME)
	@printf "[\033[0;31mdeleted\033[0m] %100s\n" $(NAME) | tr ' ' '.'

re : fclean all

.PHONY : all clean fclean re
