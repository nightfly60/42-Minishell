NAME = minishell

OBJDIR = obj

LIBFT_DIR = libft
LIBFT := $(LIBFT_DIR)/libft.a

PARSING =	parsing/tokenize/count_token.c parsing/tokenize/token_utils.c parsing/tokenize/get_tokens.c parsing/utils/is_even.c parsing/expansions/ft_expand_dquotes.c \
			parsing/expansions/ft_alias_expansion.c parsing/tokenize/ft_merge_tokens.c parsing/cmds/args.c parsing/cmds/parse_cmds.c \
			parsing/parse_errors/check_operators.c parsing/parse_errors/parse_errors.c parsing/expansions/ft_expansion.c parsing/expansions/ft_word_expansion.c \
			parsing/expansions/ft_expand_squotes.c parsing/parse_errors/check_quotes.c parsing/expansions/ft_expand_eof.c parsing/expansions/ft_exit_code_exp.c

BUILT_IN =	built-in/alias/find_alias.c built-in/alias/ft_add_alias.c  built-in/alias/ft_alias.c built-in/alias/ft_modify_alias.c built-in/alias/ft_print_alias.c \
			built-in/alias/ft_unalias.c built-in/alias/clear_alias.c built-in/is_builtin.c built-in/unset/ft_unset.c built-in/echo/ft_echo.c built-in/cd/ft_cd.c \
			built-in/pwd/ft_pwd.c built-in/env/ft_env.c built-in/exit/ft_exit.c built-in/exit/print_error.c built-in/export/ft_export.c \
			built-in/export/print_export_env.c

ENVIRNMT =	environment/new_env.c environment/copy_env.c environment/env_utils.c environment/find_var.c environment/valid_id.c environment/convert_env.c \
			environment/modify_env.c

UTILS =		minishell_utils/free_line.c minishell_utils/init_exit.c

REDIR =		file_redirection/set_finals_fd.c file_redirection/ft_heredoc.c file_redirection/open_files.c file_redirection/redirect_input.c \
				file_redirection/redirect_output.c

EXEC =		exec/exec.c exec/close.c exec/get_path.c exec/exit_wait.c exec/handle_directory.c

SIGNALS =	signals/gestionnaire.c signals/handle_signal.c signals/init_signals.c

FILES =		main.c $(PARSING) $(BUILT_IN) $(ENVIRNMT) $(UTILS) $(REDIR) $(EXEC) $(SIGNALS)

LIBFT_SRCS :=	libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
				libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
				libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c \
				libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c \
				libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_lstadd_front_bonus.c \
				libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
				libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c \
				libft/ft_putnbr_unsigned.c libft/ft_printf.c libft/get_next_line/get_next_line.c \
				libft/get_next_line/get_next_line_utils.c libft/ft_freeall.c libft/ft_lstget.c libft/ft_lstget.c

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(FILES))

INCLUDES = includes
INCLUDE_FILES = includes/minishell.h includes/ft_signals.h includes/parsing.h \
				includes/ft_redirection.h includes/ft_exec.h includes/ft_env.h includes/ft_built_in.h

RESET =	\033[0m
GRAY =	\033[1;90m
ORGE =	\033[1;33m
BLUE =	\033[1;34m
PINK =	\033[1;35m

all: $(LIBFT) $(NAME)
	@echo "$(ORGE) 🐚 PacoShell Compiled$(RESET)"

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -lreadline

$(OBJDIR)/%.o: %.c $(INCLUDE_FILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(BLUE) 🧹 PacoShell cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(PINK) 🗑️  PacoShell executable cleaned$(RESET)"

re: fclean all

.PHONY: fclean clean all re
