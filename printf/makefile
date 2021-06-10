.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -O2

NAME = libftprintf.a

# HEADERS
LIB_I_DIR = include/
LIB_I = ft_printf.h
LIB_I := $(addprefix $(LIB_I_DIR), $(LIB_I))

# SOURCES
LIB_S_DIR = src/
LIB_S = \
	printf \
	parse \
	work_with_s \
	work_with_c \
	work_with_dipouxx \
	extra
LIB_S := $(addsuffix .c, $(LIB_S))
LIB_S := $(addprefix $(LIB_S_DIR), $(LIB_S))

#OBJECTS
LIB_O_DIR = obj/
LIB_O = $(patsubst $(LIB_S_DIR)%, $(LIB_O_DIR)%, $(LIB_S))
LIB_O := $(patsubst %.c, %.o, $(LIB_O))

# $@ - имя текущей цели
# $< - имя первой цели из списка зависимостей
# $^ - весь список зависимостей

all: $(NAME)

$(NAME): $(LIB_O_DIR) $(LIB_O)
	@ar rc $(NAME) $(LIB_O)
	@ranlib $(NAME)
	@echo "------------------\nPRINTEFIK COMPILED"

$(LIB_O_DIR):
	@mkdir -p $(LIB_O_DIR)

$(LIB_O_DIR)%.o: $(LIB_S_DIR)%.c $(LIB_I)
	@echo $<
	@$(CC) -c -I $(LIB_I_DIR) $< -o $@

clean:
	@rm -rf $(LIB_O_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

# @rm -rf $(LIB_O_DIR)
# @rm -rf src/*.o
# @rm -rf obj/
# @rm -rf $(NAME)
