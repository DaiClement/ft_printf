# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:48:38 by cdai              #+#    #+#              #
#    Updated: 2019/12/03 14:40:39 by cdai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	\
			libft/ft_atoi.c\
			libft/ft_isdigit.c\
			libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_strlen.c\
			libft/ft_atoi_printf.c\
			libft/ft_count_pow.c\
			libft/ft_putlnbr.c\
			libft/ft_putlnbr_base.c\
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

BONUSOBJS	=	${BONUSSRCS:.c=.o}

NAME	=	libftprintf.a

CFLAGS	=	-o ${FLAGS}
FLAGS	=	-Wall -Wextra -Werror

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RANLIB	=	ranlib

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}
		${RANLIB} ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	${OBJS} ${BONUSOBJS}
		${AR} ${NAME} ${OBJS} ${BONUSOBJS}

fcleanbonus: clean fclean
		${RM} ${BONUSOBJS}

norm:
		norminette -R CheckForbiddenSourceHeader ft_printf*.c ft_printf*.h
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
