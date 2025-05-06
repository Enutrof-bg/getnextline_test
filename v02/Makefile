

all : get_next_line.o get_next_line_utils.o
	ar -rcs -o libget_next_line.a $^

get_next_line.o :
	cc -Wall -Wextra -Werror -c get_next_line.c

get_next_line_utils.o :
	cc -Wall -Wextra -Werror -c get_next_line_utils.c

clean :
	rm -f *.o

fclean : clean
	rm -f *.a

re : fclean
	make