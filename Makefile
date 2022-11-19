# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 14:27:22 by yongmkim          #+#    #+#              #
#    Updated: 2022/11/19 19:11:17 by yongmkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	cc
C_W_FLAG	=	all extra error
CFLAGS		:=	$(addprefix -W, $(C_W_FLAG))
# RM			=	rm
RM_FLAG		=	-r
AR			=	ar
ARFLAGS		=	rcus

SRC			=	ft_libc_ctype_convert.c \
				ft_libc_ctype_syntax.c \
				ft_libc_stdlib.c \
				ft_libc_string_cpy.c \
				ft_libc_string_locate_and_compare.c \
				ft_libc_string_util.c \
				ft_util_io.c \
				ft_util_string_sub.c \
				ft_util_string.c \

SRC_B		=	ft_list_lib_util_bonus.c \
				ft_list_lib_bonus.c \

INC_DIR		=	.
LIB_LNK		=	-I $(INC_DIR)
OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_B		=	$(addprefix $(OBJ_DIR), $(SRC_B:.c=.o))

ifdef WITH_BONUS
	OBJECT	=	$(OBJ) $(OBJ_B)
else
	OBJECT	=	$(OBJ)
endif

#==============================================================================
#	Make Part
#==============================================================================

.DEFAULT_GOAL	:=	all

.PHONY		:	all
all			:	$(NAME)

$(NAME)		:	$(OBJECT)
		$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		$(CC) $(CFLAGS) $(LIB_LNK) -o $@ -c $<

$(OBJ_DIR)	:
		mkdir -p $(OBJ_DIR)

$(OBJECT)	:	| $(OBJ_DIR)

.PHONY		:	c clear clean f fclear fclean re b bonus
c			:	clean
clear		:	clean
clean		:
		$(RM) $(RM_FLAG) $(OBJ_DIR)

f			:	fclean
fclear		:	fclean
fclean		:
		make clean
		$(RM) $(RM_FLAG) $(NAME)

re			:
		make fclean
		make all

b			:	bonus
bonus		:
		make WITH_BONUS=1 all

#==============================================================================
#░░░░░░░░░░░░░░░░░░░░██╗░░░██╗░█████╗░███╗░░░███╗░█████╗░░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░╚██╗░██╔╝██╔══██╗████╗░████║██╔══██╗░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░╚████╔╝░██║░░██║██╔████╔██║███████║░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░╚██╔╝░░██║░░██║██║╚██╔╝██║██╔══██║░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░██║░░░╚█████╔╝██║░╚═╝░██║██║░░██║░░░░░░░░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░╚═╝░░░░╚════╝░╚═╝░░░░░╚═╝╚═╝░░╚═╝░░░░░░░░░░░░░░░░░░░░░░
#==============================================================================
