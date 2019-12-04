# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:48:38 by cdai              #+#    #+#              #
#    Updated: 2019/12/04 11:34:15 by cdai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	\
			ft_printf.c\
			ft_printf_utils.c\
			ft_printf_char.c\
			ft_printf_string.c\
			ft_printf_int_p.c\
			ft_i_negative.c\
			ft_printf_unsigned.c\
			ft_printf_hexa_lower.c\
			ft_printf_hexa_upper.c\
			ft_printf_pointer.c\

PATH_LIBFT=	./libft/

LIBFTSRCS=	\
			${PATH_LIBFT}ft_atoi.c\
			${PATH_LIBFT}ft_isdigit.c\
			${PATH_LIBFT}ft_putchar_fd.c\
			${PATH_LIBFT}ft_putstr_fd.c\
			${PATH_LIBFT}ft_putnbr_fd.c\
			${PATH_LIBFT}ft_strlen.c\
			${PATH_LIBFT}ft_atoi_printf.c\
			${PATH_LIBFT}ft_count_pow.c\
			${PATH_LIBFT}ft_putlnbr.c\
			${PATH_LIBFT}ft_putlnbr_base.c\

TEST	=	\
			test.c\
			test_char.c\
			test_string.c\
			test_int.c\
			test_unsigned.c\
			test_hex_lower.c\
			test_hex_upper.c\
			test_pointer.c\

OBJS	=	${SRCS:.c=.o}

LIBFTOBJS=	${LIBFTSRCS:.c=.o}

NAME	=	libftprintf.a

CFLAGS	=	-o ${FLAGS}
FLAGS	=	-Wall -Wextra -Werror

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RANLIB	=	ranlib

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBFTOBJS}
		make -C libft
		${AR} ${NAME} ${OBJS} ${LIBFTOBJS}
		${RANLIB} ${NAME}

all:	${NAME}

clean:
		make clean -C libft
		${RM} ${OBJS}

fclean:	clean
		make fclean -C libft
		${RM} ${NAME}

re:		fclean all

bonus:	all

fcleanbonus: clean fclean

norm:
		norminette -R CheckForbiddenSourceHeader ft_printf*.c ft_printf*.h ft_i_negative.c
		norminette -R CheckForbiddenSourceHeader libft/ft_*.c libft/*.h

compile: re
		${CC} test.c -L. -lftprintf

test:	re
		rm -f expected user.output
		${CC} ${FLAGS} ${TEST} -L. -lftprintf
		./a.out 0 c | cat -e > expected
		./a.out 1 c | cat -e > user.output
		diff expected user.output
		./a.out 0 s | cat -e >> expected
		./a.out 1 s | cat -e >> user.output
		diff expected user.output
		./a.out 0 i | cat -e >> expected
		./a.out 1 i | cat -e >> user.output
		diff expected user.output
		./a.out 0 u | cat -e >> expected
		./a.out 1 u | cat -e >> user.output
		diff expected user.output
		./a.out 0 x | cat -e >> expected
		./a.out 1 x | cat -e >> user.output
		diff expected user.output
		./a.out 0 X | cat -e >> expected
		./a.out 1 X | cat -e >> user.output
		diff expected user.output
		./a.out 0 p | cat -e >> expected
		./a.out 1 p | cat -e >> user.output
		diff expected user.output

testWF:	re ${TESTOBJS}
		rm -f expected user.output
		${CC} ${TEST} -L. -lftprintf
		./a.out 0 c | cat -e > expected
		./a.out 1 c | cat -e > user.output
		diff expected user.output
		./a.out 0 s | cat -e >> expected
		./a.out 1 s | cat -e >> user.output
		diff expected user.output
		./a.out 0 i | cat -e >> expected
		./a.out 1 i | cat -e >> user.output
		diff expected user.output
		./a.out 0 u | cat -e >> expected
		./a.out 1 u | cat -e >> user.output
		diff expected user.output
		./a.out 0 x | cat -e >> expected
		./a.out 1 x | cat -e >> user.output
		diff expected user.output
		./a.out 0 X | cat -e >> expected
		./a.out 1 X | cat -e >> user.output
		diff expected user.output
		./a.out 0 p | cat -e >> expected
		./a.out 1 p | cat -e >> user.output
		diff expected user.output

commit:
		git add -A && git commit

.PHONY : all clean fclean re norm test commit bonus fcleanbonus
