#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <snikitin@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 20:52:13 by snikitin          #+#    #+#              #
#    Updated: 2018/02/07 20:53:44 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = .

SRCS = $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_memcpy.c \
	   $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isalnum.c \
	   $(SRC_DIR)/ft_isascii.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_toupper.c \
	   $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_memccpy.c $(SRC_DIR)/ft_memmove.c \
	   $(SRC_DIR)/ft_memchr.c $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_strlen.c\
	   $(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_strcpy.c $(SRC_DIR)/ft_strncpy.c \
	   $(SRC_DIR)/ft_strcat.c $(SRC_DIR)/ft_strncat.c $(SRC_DIR)/ft_strlcat.c \
	   $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_atoi.c\
	   $(SRC_DIR)/ft_strchr.c $(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strstr.c\
	   $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c\
	   $(SRC_DIR)/ft_putendl.c $(SRC_DIR)/ft_putnbr.c $(SRC_DIR)/ft_putchar_fd.c\
	   $(SRC_DIR)/ft_putstr_fd.c $(SRC_DIR)/ft_putendl_fd.c\
	   $(SRC_DIR)/ft_putnbr_fd.c $(SRC_DIR)/ft_memdel.c $(SRC_DIR)/ft_strnew.c\
	   $(SRC_DIR)/ft_strdel.c $(SRC_DIR)/ft_strclr.c\
	   $(SRC_DIR)/ft_striter.c $(SRC_DIR)/ft_striteri.c $(SRC_DIR)/ft_strmap.c\
	   $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_strequ.c\
	   $(SRC_DIR)/ft_strnequ.c $(SRC_DIR)/ft_strsub.c $(SRC_DIR)/ft_strjoin.c\
	   $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_strsplit.c\
	   $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_lstnew.c $(SRC_DIR)/ft_lstdelone.c\
	   $(SRC_DIR)/ft_lstdel.c $(SRC_DIR)/ft_lstadd.c $(SRC_DIR)/ft_lstiter.c\
	   $(SRC_DIR)/ft_lstmap.c $(SRC_DIR)/ft_list_push_back.c\
	   $(SRC_DIR)/ft_list_push_front.c $(SRC_DIR)/ft_list_at.c\
	   $(SRC_DIR)/ft_list_find.c $(SRC_DIR)/ft_list_last.c\
	   $(SRC_DIR)/ft_cntwrd.c $(SRC_DIR)/ft_cntchr.c $(SRC_DIR)/ft_iswhsp.c\
	   $(SRC_DIR)/ft_strjoin_free.c $(SRC_DIR)/ft_atoi_base.c\
	   $(SRC_DIR)/ft_list_count.c $(SRC_DIR)/ft_swap_int.c\
	   $(SRC_DIT)/get_next_line.c

OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o \
	  ft_memcmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o\
	  ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o\
	  ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o\
	  ft_strlcat.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_strchr.o ft_strrchr.o\
	  ft_strstr.o ft_strnstr.o ft_putchar.o ft_putstr.o ft_putendl.o\
	  ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o\
	  ft_putnbr_fd.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o\
	  ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o\
	  ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o\
	  ft_strsplit.o ft_itoa.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o\
	  ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_list_push_back.o\
	  ft_list_push_front.o ft_list_at.o ft_list_find.o ft_list_last.o\
	  ft_cntwrd.o ft_cntchr.o ft_iswhsp.o ft_strjoin_free.o\
	  ft_atoi_base.o ft_list_count.o ft_swap_int.o\
	  get_next_line.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

NAME = libft.a

INCLUDES = ./libft.h

all: $(NAME)
	
$(NAME) : $(OBJ) $(INCLUDES)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -r -f $(OBJ)

fclean: clean
	/bin/rm -r -f $(NAME)

re:	fclean all

ft_memset.o : $(SRC_DIR)/ft_memset.c
	$(CC) $(CFLAGS) -c -o ft_memset.o $(SRC_DIR)/ft_memset.c

ft_bzero.o : $(SRC_DIR)/ft_bzero.c
	$(CC) $(CFLAGS) -c -o ft_bzero.o $(SRC_DIR)/ft_bzero.c

ft_memcpy.o : $(SRC_DIR)/ft_memcpy.c
	$(CC) $(CFLAGS) -c -o ft_memcpy.o $(SRC_DIR)/ft_memcpy.c

ft_memmove.o : $(SRC_DIR)/ft_memmove.c
	$(CC) $(CFLAGS) -c -o ft_memmove.o $(SRC_DIR)/ft_memmove.c

ft_memchr.o : $(SRC_DIR)/ft_memchr.c
	$(CC) $(CFLAGS) -c -o ft_memchr.o $(SRC_DIR)/ft_memchr.c

ft_memccpy.o : $(SRC_DIR)/ft_memccpy.c
	$(CC) $(CFLAGS) -c -o ft_memccpy.o $(SRC_DIR)/ft_memccpy.c

ft_memcmp.o : $(SRC_DIR)/ft_memcmp.c
	$(CC) $(CFLAGS) -c -o ft_memcmp.o $(SRC_DIR)/ft_memcmp.c

ft_strlen.o : $(SRC_DIR)/ft_strlen.c
	$(CC) $(CFLAGS) -c -o ft_strlen.o $(SRC_DIR)/ft_strlen.c

ft_strdup.o : $(SRC_DIR)/ft_strdup.c
	$(CC) $(CFLAGS) -c -o ft_strdup.o $(SRC_DIR)/ft_strdup.c

ft_strcpy.o : $(SRC_DIR)/ft_strcpy.c
	$(CC) $(CFLAGS) -c -o ft_strcpy.o $(SRC_DIR)/ft_strcpy.c

ft_strncpy.o : $(SRC_DIR)/ft_strncpy.c
	$(CC) $(CFLAGS) -c -o ft_strncpy.o $(SRC_DIR)/ft_strncpy.c

ft_strcat.o : $(SRC_DIR)/ft_strcat.c
	$(CC) $(CFLAGS) -c -o ft_strcat.o $(SRC_DIR)/ft_strcat.c

ft_strncat.o : $(SRC_DIR)/ft_strncat.c
	$(CC) $(CFLAGS) -c -o ft_strncat.o $(SRC_DIR)/ft_strncat.c

ft_strlcat.o : $(SRC_DIR)/ft_strlcat.c
	$(CC) $(CFLAGS) -c -o ft_strlcat.o $(SRC_DIR)/ft_strlcat.c

ft_strcmp.o : $(SRC_DIR)/ft_strcmp.c
	$(CC) $(CFLAGS) -c -o ft_strcmp.o $(SRC_DIR)/ft_strcmp.c

ft_strncmp.o : $(SRC_DIR)/ft_strncmp.c
	$(CC) $(CFLAGS) -c -o ft_strncmp.o $(SRC_DIR)/ft_strncmp.c

ft_isalpha.o : $(SRC_DIR)/ft_isalpha.c
	$(CC) $(CFLAGS) -c -o ft_isalpha.o $(SRC_DIR)/ft_isalpha.c

ft_isdigit.o : $(SRC_DIR)/ft_isdigit.c
	$(CC) $(CFLAGS) -c -o ft_isdigit.o $(SRC_DIR)/ft_isdigit.c

ft_isalnum.o : $(SRC_DIR)/ft_isalnum.c
	$(CC) $(CFLAGS) -c -o ft_isalnum.o $(SRC_DIR)/ft_isalnum.c

ft_isascii.o : $(SRC_DIR)/ft_isascii.c
	$(CC) $(CFLAGS) -c -o ft_isascii.o $(SRC_DIR)/ft_isascii.c

ft_isprint.o : $(SRC_DIR)/ft_isprint.c
	$(CC) $(CFLAGS) -c -o ft_isprint.o $(SRC_DIR)/ft_isprint.c

ft_toupper.o : $(SRC_DIR)/ft_toupper.c
	$(CC) $(CFLAGS) -c -o ft_toupper.o $(SRC_DIR)/ft_toupper.c

ft_tolower.o : $(SRC_DIR)/ft_tolower.c
	$(CC) $(CFLAGS) -c -o ft_tolower.o $(SRC_DIR)/ft_tolower.c

ft_atoi.o : $(SRC_DIR)/ft_atoi.c
	$(CC) $(CFLAGS) -c -o ft_atoi.o $(SRC_DIR)/ft_atoi.c

ft_strchr.o : $(SRC_DIR)/ft_strchr.c
	$(CC) $(CFLAGS) -c -o ft_strchr.o $(SRC_DIR)/ft_strchr.c

ft_strrchr.o : $(SRC_DIR)/ft_strrchr.c
	$(CC) $(CFLAGS) -c -o ft_strrchr.o $(SRC_DIR)/ft_strrchr.c

ft_strstr.o : $(SRC_DIR)/ft_strstr.c
	$(CC) $(CFLAGS) -c -o ft_strstr.o $(SRC_DIR)/ft_strstr.c

ft_strnstr.o : $(SRC_DIR)/ft_strnstr.c
	$(CC) $(CFLAGS) -c -o ft_strnstr.o $(SRC_DIR)/ft_strnstr.c

ft_putchar.o : $(SRC_DIR)/ft_putchar.c
	$(CC) $(CFLAGS) -c -o ft_putchar.o $(SRC_DIR)/ft_putchar.c

ft_putstr.o : $(SRC_DIR)/ft_putstr.c
	$(CC) $(CFLAGS) -c -o ft_putstr.o $(SRC_DIR)/ft_putstr.c

ft_putendl.o : $(SRC_DIR)/ft_putendl.c
	$(CC) $(CFLAGS) -c -o ft_putendl.o $(SRC_DIR)/ft_putendl.c

ft_putnbr.o : $(SRC_DIR)/ft_putnbr.c
	$(CC) $(CFLAGS) -c -o ft_putnbr.o $(SRC_DIR)/ft_putnbr.c

ft_putchar_fd.o : $(SRC_DIR)/ft_putchar_fd.c
	$(CC) $(CFLAGS) -c -o ft_putchar_fd.o $(SRC_DIR)/ft_putchar_fd.c

ft_putstr_fd.o : $(SRC_DIR)/ft_putstr_fd.c
	$(CC) $(CFLAGS) -c -o ft_putstr_fd.o $(SRC_DIR)/ft_putstr_fd.c

ft_putendl_fd.o : $(SRC_DIR)/ft_putendl_fd.c
	$(CC) $(CFLAGS) -c -o ft_putendl_fd.o $(SRC_DIR)/ft_putendl_fd.c

ft_putnbr_fd.o : $(SRC_DIR)/ft_putnbr_fd.c
	$(CC) $(CFLAGS) -c -o ft_putnbr_fd.o $(SRC_DIR)/ft_putnbr_fd.c

ft_memalloc.o : $(SRC_DIR)/ft_memalloc.c
	$(CC) $(CFLAGS) -c -o ft_memalloc.o $(SRC_DIR)/ft_memalloc.c

ft_memdel.o : $(SRC_DIR)/ft_memdel.c
	$(CC) $(CFLAGS) -c -o ft_memdel.o $(SRC_DIR)/ft_memdel.c

ft_strnew.o : $(SRC_DIR)/ft_strnew.c
	$(CC) $(CFLAGS) -c -o ft_strnew.o $(SRC_DIR)/ft_strnew.c

ft_strdel.o : $(SRC_DIR)/ft_strdel.c
	$(CC) $(CFLAGS) -c -o ft_strdel.o $(SRC_DIR)/ft_strdel.c

ft_strclr.o : $(SRC_DIR)/ft_strclr.c
	$(CC) $(CFLAGS) -c -o ft_strclr.o $(SRC_DIR)/ft_strclr.c

ft_striter.o : $(SRC_DIR)/ft_striter.c
	$(CC) $(CFLAGS) -c -o ft_striter.o $(SRC_DIR)/ft_striter.c

ft_striteri.o : $(SRC_DIR)/ft_striteri.c
	$(CC) $(CFLAGS) -c -o ft_striteri.o $(SRC_DIR)/ft_striteri.c

ft_strmap.o : $(SRC_DIR)/ft_strmap.c
	$(CC) $(CFLAGS) -c -o ft_strmap.o $(SRC_DIR)/ft_strmap.c

ft_strmapi.o : $(SRC_DIR)/ft_strmapi.c
	$(CC) $(CFLAGS) -c -o ft_strmapi.o $(SRC_DIR)/ft_strmapi.c

ft_strequ.o : $(SRC_DIR)/ft_strequ.c
	$(CC) $(CFLAGS) -c -o ft_strequ.o $(SRC_DIR)/ft_strequ.c

ft_strnequ.o : $(SRC_DIR)/ft_strnequ.c
	$(CC) $(CFLAGS) -c -o ft_strnequ.o $(SRC_DIR)/ft_strnequ.c

ft_strsub.o : $(SRC_DIR)/ft_strsub.c
	$(CC) $(CFLAGS) -c -o ft_strsub.o $(SRC_DIR)/ft_strsub.c

ft_strjoin.o : $(SRC_DIR)/ft_strjoin.c
	$(CC) $(CFLAGS) -c -o ft_strjoin.o $(SRC_DIR)/ft_strjoin.c

ft_strtrim.o : $(SRC_DIR)/ft_strtrim.c
	$(CC) $(CFLAGS) -c -o ft_strtrim.o $(SRC_DIR)/ft_strtrim.c

ft_strsplit.o : $(SRC_DIR)/ft_strsplit.c
	$(CC) $(CFLAGS) -c -o ft_strsplit.o $(SRC_DIR)/ft_strsplit.c

ft_itoa.o : $(SRC_DIR)/ft_itoa.c
	$(CC) $(CFLAGS) -c -o ft_itoa.o $(SRC_DIR)/ft_itoa.c

ft_lstnew.o : $(SRC_DIR)/ft_lstnew.c
	$(CC) $(CFLAGS) -c -o ft_lstnew.o $(SRC_DIR)/ft_lstnew.c

ft_lstdelone.o : $(SRC_DIR)/ft_lstdelone.c
	$(CC) $(CFLAGS) -c -o ft_lstdelone.o $(SRC_DIR)/ft_lstdelone.c

ft_lstdel.o : $(SRC_DIR)/ft_lstdel.c
	$(CC) $(CFLAGS) -c -o ft_lstdel.o $(SRC_DIR)/ft_lstdel.c

ft_lstadd.o : $(SRC_DIR)/ft_lstadd.c
	$(CC) $(CFLAGS) -c -o ft_lstadd.o $(SRC_DIR)/ft_lstadd.c

ft_lstiter.o : $(SRC_DIR)/ft_lstiter.c
	$(CC) $(CFLAGS) -c -o ft_lstiter.o $(SRC_DIR)/ft_lstiter.c

ft_lstmap.o : $(SRC_DIR)/ft_lstmap.c
	$(CC) $(CFLAGS) -c -o ft_lstmap.o $(SRC_DIR)/ft_lstmap.c

ft_list_push_back.o : $(SRC_DIR)/ft_list_push_back.c
	$(CC) $(CFLAGS) -c -o ft_list_push_back.o $(SRC_DIR)/ft_list_push_back.c

ft_list_push_front.o : $(SRC_DIR)/ft_list_push_front.c
	$(CC) $(CFLAGS) -c -o ft_list_push_front.o $(SRC_DIR)/ft_list_push_front.c

ft_list_find.o : $(SRC_DIR)/ft_list_find.c
	$(CC) $(CFLAGS) -c -o ft_list_find.o $(SRC_DIR)/ft_list_find.c

ft_list_at.o : $(SRC_DIR)/ft_list_at.c
	$(CC) $(CFLAGS) -c -o ft_list_at.o $(SRC_DIR)/ft_list_at.c

ft_list_last.o : $(SRC_DIR)/ft_list_last.c
	$(CC) $(CFLAGS) -c -o ft_list_last.o $(SRC_DIR)/ft_list_last.c
	
ft_cntwrd.o : $(SRC_DIR)/ft_cntwrd.c
	$(CC) $(CFLAGS) -c -o ft_cntwrd.o $(SRC_DIR)/ft_cntwrd.c

ft_cntchr.o : $(SRC_DIR)/ft_cntchr.c
	$(CC) $(CFLAGS) -c -o ft_cntchr.o $(SRC_DIR)/ft_cntchr.c

ft_iswhsp.o : $(SRC_DIR)/ft_iswhsp.c
	$(CC) $(CFLAGS) -c -o ft_iswhsp.o $(SRC_DIR)/ft_iswhsp.c

ft_strjoin_free.o : $(SRC_DIR)/ft_strjoin_free.c
	$(CC) $(CFLAGS) -c -o ft_strjoin_free.o $(SRC_DIR)/ft_strjoin_free.c

ft_atoi_base.o : $(SRC_DIR)/ft_atoi_base.c
	$(CC) $(CFLAGS) -c -o ft_atoi_base.o $(SRC_DIR)/ft_atoi_base.c

ft_list_count.o : $(SRC_DIR)/ft_list_count.c
	$(CC) $(CFLAGS) -c -o ft_list_count.o $(SRC_DIR)/ft_list_count.c

ft_swap_int.o : $(SRC_DIR)/ft_swap_int.c
	$(CC) $(CFLAGS) -c -o ft_swap_int.o $(SRC_DIR)/ft_swap_int.c

get_next_line.o : $(SRC_DIR)/get_next_line.c
	$(CC) $(CFLAGS) -c -o get_next_line.o $(SRC_DIR)/get_next_line.c
