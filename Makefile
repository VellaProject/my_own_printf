# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avella <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:17:03 by avella            #+#    #+#              #
#    Updated: 2016/05/02 17:51:46 by avella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = "includes"

SRC=ft_putchar.c ft_putstr.c ft_tolower.c ft_toupper.c ft_strlen.c \
	ft_memset.c ft_strcpy.c ft_isascii.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isprint.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_strdup.c ft_bzero.c ft_putnbr.c \
	ft_strchr.c ft_strrchr.c ft_atoi.c ft_strdel.c ft_memcpy.c \
	ft_memalloc.c ft_strclr.c ft_strncpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c  ft_strlcat.c\
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_memdel.c \
	ft_strnew.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c ft_itoa.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	converter.c conv_arg.c first_arg.c largeur_minimum.c \
	long_short.c precision.c printf.c my_itoa.c my_utoa.c wchar.c \
	all_d.c all_du_bis.c all_u.c arg_cs.c \
        arg_di.c arg_ou.c arg_p.c arg_percent.c arg_px.c arg_s.c \
	all_first_argc.c norme_first_arg.c norme_second_width.c norme_width.c \
	norme_wchar.c

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): ./includes/libft.h $(SRC)
	$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
