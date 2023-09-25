MAKEFLAGS += --silent

HEADER = ./

SRC = ./src/

GNL = ./src/gnl/

FILES_C = ${SRC}ft_pipex.c \
		  ${SRC}ft_pipex_more.c \
		  ${SRC}ft_pipex_more_more.c \
		  ${GNL}get_next_line_bonus.c \
		  ${GNL}get_next_line_utils_bonus.c \

LIBFT_PATH = ${SRC}printf/

LIBFT = -L${LIBFT_PATH} -lftprintf

FILES_O = ${FILES_C:.c=.o}

FILES_H = ${HEADER}ft_pipex.h

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

NAME = ./tmp/pipex

all: ${NAME}

${LIBFT}:
	make -C ${LIBFT_PATH} all bonus

${NAME}: ${LIBFT} ${FILES_O}
	${CC} ${FLAGS} ${FILES_O} ${LIBFT} -I ${FILES_H} -I ${GNL}get_next_line_bonus.h -o ${NAME} \
		&& echo "Make done successfully." \ || echo "Doesn't work, sadge. :c"

clean:
	rm -f ${FILES_O}
	make -C ${LIBFT_PATH} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_PATH} fclean \
	&& echo "Fclean done successfully." \ || echo "Haha your fclean suck."

re: fclean all

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

# Colors
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'
