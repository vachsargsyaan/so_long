NAME			=	so_long
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs
SRCS			=	get_next_line_bonus.c get_next_line_utils_bonus.c\
					ft_printnum.c ft_printf.c ft_cahrs.c ft_it.c\
					ft_print_hex.c ft_print_point.c main.c

BONUS_SRCS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
					ft_lstmap.c
OBJS			=	$(patsubst %.c, %.o, $(SRCS)) # generating .o filenames from src files`.c ex` ft_atoi.c -> ft_atoi.o
BONUS_OBJS		=	$(patsubst %.c, %.o, $(BONUS_SRCS)) # same for bonus filenames
.DEFAULT_GOAL	=	all

%.o:	%.c # compiles src files`.c and generate .o files ex` ft_atoi.c -> ft_atoi.o
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) # add only newer objects to the archive
	$(AR)	$(NAME) $?

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus:	$(BONUS_OBJS)
	$(AR)	$(NAME) $?

.PHONY:	all clean fclean re bonus

