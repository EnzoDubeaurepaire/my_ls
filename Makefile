##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Placeholder
##

SRC	=	src/my_ls.c \
		src/errors.c \
		src/get_files_input.c \
		src/get_flags.c \
		src/get_input.c \
		src/sort.c \
		include/my_strcat.c \
		include/my_strcpy.c \
		include/my_strlen.c \
		src/lflag.c \
		include/my_putnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)
