SRCS		=	ft_strlen.s ft_strcpy.s
OBJS		=	$(SRCS:.s=.o)

NASM		=	nasm
NASM_FLAGS	=	-f macho64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	test

%.o:			%.s
				@$(NASM) $(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(NAME) $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				@gcc $(FLAGS) $(NAME) -o $(TEST) test.c
				@./$(TEST)

.PHONY:			clean fclean re test