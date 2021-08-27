NAME := karenFilter
 
SRCS := main.cpp Fixed.cpp

OBJS := ${patsubst %.cpp,%.o,${SRCS}}
D_FILES := ${patsubst %.cpp,%.d,${SRCS}}

GCC := clang++
FLAGS := -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME} : ${OBJS}
	${GCC} ${OBJS} -o ${NAME}

%.o : %.cpp
	${GCC} ${FLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:
	rm -rf ${OBJS} ${D_FILES}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re