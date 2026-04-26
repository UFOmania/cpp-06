FLAGS	=	-Wall -Wextra -Werror
SRC		=	ScalarConverter.cpp		main.cpp
OBJ		=	$(SRC:.cpp=.o)


NAME	=	convert
all: $(NAME)

$(NAME)	: $(OBJ)
	c++ $(OBJ) $(FLAGS) -o $@

%.o	:	%.cpp ScalarConverter.hpp
	c++ $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all