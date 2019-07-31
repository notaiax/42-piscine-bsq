NAME = bsq

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f *.o libft.a

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: clean all

libft.a: libs/ft_string.c libs/ft_read_file.c
	gcc -Wall -Wextra -Werror -c $^
	ar rc $@ *.o
	ranlib $@

$(NAME): main.c headers/bsq.h libft.a
	gcc -Wall -Wextra -Werror -L. -lft -Iheaders -o $(NAME) $<

