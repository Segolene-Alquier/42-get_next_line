# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salquier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 16:14:18 by salquier          #+#    #+#              #
#    Updated: 2018/11/23 17:12:54 by salquier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c \
	  ft_toupper.c ft_tolower.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strcmp.c ft_atoi.c ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memccpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	  ft_strncat.c ft_strstr.c ft_strnstr.c ft_memchr.c ft_memcmp.c \
	  ft_memmove.c ft_strlcat.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_strnew.c ft_strclr.c ft_strdel.c ft_memalloc.c ft_memdel.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	  ft_itoa.c ft_putnbr.c ft_count_words.c ft_sort_integer_table.c \
	  ft_swap.c ft_is_strchr.c ft_occurence_chr.c ft_lstnew.c ft_lstadd.c \
	  ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_is_word_after.c

CFLAGS = -c -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

.PHONY: all clean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar cr $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)
