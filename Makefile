NAME			= so_long
SRC_DIR 		= src
SRCS			= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard includes/*.h)
OBJ_DIR			= obj
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
INCS			= -Iincludes
CC				= cc 
LINKERS			= -lmlx -framework  OpenGL -framework AppKit
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MK				= mkdir -p

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(LINKERS)

clean:			
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re bonus

