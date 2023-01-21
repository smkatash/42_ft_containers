
VPATH	= src

CC		=	c++
CFLAGS	=	-std=c++98 -Wall -Wextra -Werror

NAME	=	tester
SRC		=	main.cpp vector.cpp map.cpp stack.cpp
OBJ		=	$(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
INC		=	-I include

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ 
	@echo "tester is compiled"

obj/%.o : %.cpp | obj
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

obj :
	@mkdir obj

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re

# Run tests ===========================
ft: ./$(NAME)
	./$(NAME) > ft_containers

stl: ./$(NAME)
	./$(NAME) > stl_containers
# Run tests ===========================

