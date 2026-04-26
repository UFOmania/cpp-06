FLAGS	=	-Wall -Wextra -Werror
SRC		=	Serializer.cpp		main.cpp
OBJ		=	$(SRC:.cpp=.o)


NAME	=	serialize
all: $(NAME)

$(NAME)	: $(OBJ)
	c++ $(OBJ) $(FLAGS) -o $@

%.o	:	%.cpp Serializer.hpp Data.hpp
	c++ $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all