# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/16 15:52:11 by rfernand          #+#    #+#              #
#    Updated: 2016/04/21 15:11:14 by rfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

NAME = libftprintf.a

SRC_NAME = apply_diez.c \
		   second_diez.c \
		   arg_forscient.c \
		   check_accuracy.c \
		   check_flags.c \
		   check_format.c \
		   check_len.c \
		   check_type.c \
		   check_modif.c \
		   fill_point.c \
		   ft_addzero.c \
		   ft_printf.c \
		   ft_round.c \
		   get_arg.c \
		   get_arg_2.c \
		   get_arg_3.c \
		   get_int.c \
		   get_unsigned_2.c \
		   get_unsigned.c \
		   get_int_2.c \
		   init_pt_tab.c \
		   print_arg.c

LIBFT_NAME = ft_atoi.c \
			 ft_bzero.c \
			 ft_convertbase.c \
			 ft_dtoa.c \
			 ft_itoa.c \
			 ft_memalloc.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_power.c \
			 ft_putchar.c \
			 ft_putnbr.c \
			 ft_putstr.c \
			 ft_strcat.c \
			 ft_strchr.c \
			 ft_strcpy.c \
			 ft_strlen.c \
			 ft_toupper.c \
			 ft_utoa.c

OBJ_PATH = obj
OBJ_PATH_LIBFT = obj_libft
SRC_PATH = SRC
LIBFT_PATH = libftprintf
OBJ_SRC_NAME = $(SRC_NAME:.c=.o)
OBJ_LIBFT_NAME = $(LIBFT_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFT_NAME))
OBJ_SRC = $(addprefix $(OBJ_PATH)/,$(OBJ_SRC_NAME))
OBJ_LIBFT = $(addprefix $(OBJ_PATH_LIBFT)/,$(OBJ_LIBFT_NAME))

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_LIBFT)
	ar r $(NAME) $^
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		clang -o $@ -c $<

$(OBJ_PATH_LIBFT)/%.o: $(LIBFT_PATH)/%.c
		@mkdir $(OBJ_PATH_LIBFT) 2> /dev/null || true
		clang -o $@ -c $<

clean:
	rm -fv $(OBJ_SRC)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	rm -fv $(OBJ_LIBFT)
	@rmdir $(OBJ_PATH_LIBFT) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all
