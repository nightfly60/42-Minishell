NAME = minishell

LIBFT_DIR = libft

OBJDIR = obj

LIBFT := $(LIBFT_DIR)/libft.a

PARSING =
READLINE = readline/ft_readline.c readline/ft_add_history.c readline/utils/delete_char.c readline/utils/insert_char.c \
		readline/utils/switch_terminal.c readline/utils/getendpos.c realine/utils/getstartpos.c
EXEC =

FILES = main.c $(PARSING) $(READLINE) $(EXEC)

LIBFT_SRCS := libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
		libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
		libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c \
		libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_lstadd_front_bonus.c \
		libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
		libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c \
		libft/ft_putnbr_unsigned.c libft/ft_printf.c libft/get_next_line/get_next_line.c \
		libft/get_next_line/get_next_line_utils.c libft/ft_freeall.c libft/ft_lstget.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(FILES))

INCLUDES = minishell.h readline/ft_readline.h

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -ltermcap

$(OBJDIR)/%.o: %.c $(INCLUDES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: fclean clean all re
