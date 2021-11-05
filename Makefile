SRC =	collisions.c exit_errors.c file_errors.c gameplay.c inits.c inputs.c main.c parser.c pipeline.c shapes.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
 		basic/ft_bzero.c basic/ft_calloc.c basic/ft_memset.c basic/ft_split.c basic/ft_strdup.c basic/ft_strjoin.c \
		 basic/ft_strlen.c basic/ft_substr.c


OBJ =	collisions.o exit_errors.o file_errors.ogameplay.o inits.o inputs.o main.o parser.o pipeline.o shapes.o \
		get_next_line.o get_next_line_utils.o \
 		ft_bzero.o ft_calloc.o ft_memset.o ft_split.o ft_strdup.o ft_strjoin.o ft_strlen.o ft_substr.o



HEADER = ./GNL/get_next_line.h so_long.h ./basic/libft.h


NAME = so_long


all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Werror -Wextra -lmlx -O3 -framework OpenGL -framework Appkit $(SRC) -o $(NAME)


norm:
	norminette $(SRC) $(HEADER)

clean:
	rm -f $OBJ
	
fclean: clean
	rm -f $(NAME)

run:
	./$(NAME) map.ber
	
re: fclean all