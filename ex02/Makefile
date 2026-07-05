FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	Base.cpp A.cpp B.cpp C.cpp main.cpp
OBJ		=	$(SRC:.cpp=.o)


NAME	=	identify
all: $(NAME)

$(NAME)	: $(OBJ)
	c++ $(OBJ) $(FLAGS) -o $@

%.o	:	%.cpp Base.hpp A.hpp B.hpp C.hpp
	c++ $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all