# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh		#for systems where SHELL variable can be inherited from environment

.SUFFIXES:			#no suffix rules are used

LIBS=				libft/libft.a

LIBS_DIR=			${dir ${LIBS}}

LIBS_INC_F=			-L ${dir ${LIBS}} -l${patsubst lib%.a, %, ${notdir ${LIBS}}}

LIBS_INC=			${foreach LIBS, ${LIBS}, ${LIBS_INC_F}}

LIBS_HEADERS=		${patsubst %.a, %.h, ${LIBS}}

HEADERS_MINITALK=	headers/minitalk.h

HEADERS_MINITALK_B=headers/minitalk.h

HEADERS=			${LIBS_HEADERS} ${HEADERS_MINITALK}

ifdef COMPILE_BONUS
HEADERS:=			${HEADERS} ${HEADERS_MINITALK_B}
endif

INC_HEADERS_FORMAT=	-I ${dir ${HEADERS}}

INC_HEADERS_DIR=	${foreach HEADERS, ${HEADERS}, ${INC_HEADERS_FORMAT}}

SRCS_C_SERVER=		src/server.c \

SRCS_C_CLIENT=		src/client.c \

SRCS_C_SERVER_B=	src/server_bonus.c \

SRCS_C_CLIENT_B=	src/client_bonus.c \

ifdef COMPILE_BONUS
SRCS_C_SERVER:=		${SRCS_C_SERVER_B}

SRCS_C_CLIENT:=		${SRCS_C_CLIENT_B}
endif

OBJ_C_SERVER=		${SRCS_C_SERVER:src/%.c=obj/%.o}

OBJ_C_CLIENT=		${SRCS_C_CLIENT:src/%.c=obj/%.o}

NAME=				minitalk

NAME_SERVER=		server

NAME_CLIENT=		client

ifdef COMPILE_BONUS
NAME_SERVER=		server

NAME_CLIENT=		client
endif

CC=					cc
RM=					rm -f
LD=					ld

ALL_CFLAGS=			-Wall -Wextra -Werror -g ${INC_HEADERDIR} ${CFLAGS}
ALL_LDFLAGS=		-g ${LDFLAGS}

NORM=				norminette ${NORMO}

.PHONY:				all clean fclean re bonus libs_make libs_clean minitalk

all:				libs_make ${NAME}

libs_make:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} bonus}

obj/%.o:			src/%.c ${HEADERS}
					${CC} ${ALL_CFLAGS} ${INC_HEADERS_DIR} -c ${<} -o ${<:src/%.c=obj/%.o}

${NAME}:			${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}:		${OBJ_C_SERVER} ${LIBS}
					${CC} ${ALL_LDFLAGS} ${OBJ_C_SERVER} ${LIBS_INC} ${LIBS_EXT} -o ${NAME_SERVER}

${NAME_CLIENT}:		${OBJ_C_CLIENT} ${LIBS}
					${CC} ${ALL_LDFLAGS} ${OBJ_C_CLIENT} ${LIBS_INC} ${LIBS_EXT} -o ${NAME_CLIENT}

bonus:
					${MAKE} COMPILE_BONUS=1 all

#$(INSTALL_PROGRAM)=	${TEST_NAME} $(DESTDIR)$(bindir)/foo	#where executeable shoud be placed
#$(INSTALL_DATA)=	${NAME} $(DESTDIR)$(libdir)/libfoo.a		#where libs shoud be placed



clean:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} clean}
					${RM} ${OBJS_C} ${OBJS_C_BONUS}

fclean:
					${foreach LIBS_DIR, ${LIBS_DIR}, ${MAKE} -C ${LIBS_DIR} fclean}
					${RM} ${OBJS_C} ${OBJS_C_BONUS}
					${RM} ${NAME_SERVER} ${NAME_CLIENT}

norm:		
					${NORM} ${LIBS_DIR} *.c *.h

re:					fclean all

# .DELETE_ON_ERROR