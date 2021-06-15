NAME =	push_swap

SRC =	main.c\
		functions.c\
		functions1.c\
		functions2.c\
		functions3.c\
		functions4.c\
		functions5.c


OBJS = ${SRC:.c=.o}



 CC = gcc

all : $(NAME)

$(NAME) : ${OBJS}
		
		$(CC) $(SRC) -o  $(NAME) -g3

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all
