# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:48:38 by cdai              #+#    #+#              #
#    Updated: 2019/11/26 08:56:05 by cdai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER	=	libftprintf.h


SRCS	=	\
			libft/ft_atoi.c\
			libft/ft_itoa.c\
			libft/ft_isdigit.c\
			libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_strlen.c\
			libft/ft_atoi_printf.c\
			libft/ft_itoa_long.c\
			libft/ft_putnbr_printf.c\
			libft/ft_count_pow.c\
			ft_printf.c\
			ft_printf_utils.c\
			ft_printf_utils2.c\

BONUSSRCS	=	

OBJS	=	${SRCS:.c=.o}

BONUSOBJS	=	${BONUSSRCS:.c=.o}

NAME	=	libftprintf.a

CFLAGS	=	-o -Wall -Wextra -Werror

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
		norminette -R CheckForbiddenSourceHeader ft_*.c *.h
		norminette -R CheckForbiddenSourceHeader libft/ft_*.c libft/*.h

compile: re
		${CC} test.c -L. -lftprintf

test:	re
		${CC} -Wall -Wextra -Werror test.c -L. -lftprintf && ./a.out 0 | cat -e
		${CC} -Wall -Wextra -Werror test.c -L. -lftprintf && ./a.out 1 | cat -e

testWF:	re
		${CC} test.c -L. -lftprintf
		./a.out 0 | cat -e > expected
		./a.out 1 | cat -e > user.output
		diff expected user.output

commit:
		git add -A && git commit

.PHONY : all clean fclean re norm test commit bonus fcleanbonus
