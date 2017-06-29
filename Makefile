
NAME = filler

all:
	gcc -Wall -Wextra -Werror filler.c -o $(NAME) libft/libft.a

clean:
	rm -rf *.o
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: fclean all