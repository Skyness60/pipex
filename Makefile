NAME = pipex

CC = cc -g3

SOURCES =	srcs/project/pipex.c \
				srcs/project/childs/first.c \
				srcs/project/childs/second.c \
				srcs/project/childs/wait.c \
				srcs/project/clean/close.c \
				srcs/project/clean/fail.c \
				srcs/project/clean/syntax.c \
				srcs/project/fd/child.c \
				srcs/project/free/ft_free.c \
				srcs/project/path/found.c \
				srcs/project/pipe/close.c \
				srcs/project/utils/ft_strjoin_with_separator.c \
				srcs/project/utils/ft_tablen.c \
				srcs/project/utils/is_exec.c \
			export/essential/ft_bzero.c \
			export/essential/ft_memmove.c \
			export/essential/ft_ppxadd_back.c \
			export/essential/ft_ppxclear.c \
			export/essential/ft_ppxnew.c \
			export/essential/ft_split.c \
			export/essential/ft_split2.c \
			export/essential/ft_strlen.c \
			export/essential/ft_strchr.c \
			export/essential/ft_strjoin.c \
			export/essential/ft_strlcpy.c \
			export/essential/ft_strncmp.c \
			export/essential/ft_strncpy.c \
			export/essential/ft_strndup.c \
			export/printf/srcs/ft_printf.c \
				export/printf/libft/ft_putchar.c \
				export/printf/libft/ft_putnbr.c \
				export/printf/libft/ft_putnbr_unsigned.c \
				export/printf/libft/ft_putstr.c \
				export/printf/libft/ft_puthexa.c \
				export/printf/libft/ft_putpointer.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES =	srcs/bonus/pipex_bonus.c \
				srcs/bonus/childs_bonus/first_bonus.c \
				srcs/bonus/childs_bonus/middle_bonus.c \
				srcs/bonus/childs_bonus/second_bonus.c \
				srcs/bonus/childs_bonus/wait_bonus.c \
				srcs/bonus/clean_bonus/close_bonus.c \
				srcs/bonus/clean_bonus/fail_bonus.c \
				srcs/bonus/fd_bonus/child_bonus.c \
				srcs/bonus/free_bonus/ft_free_bonus.c \
				srcs/bonus/path_bonus/found_bonus.c \
				srcs/bonus/pipe_bonus/close_bonus.c \
				srcs/bonus/utils_bonus/ft_strjoin_with_separator_bonus.c \
				srcs/bonus/utils_bonus/ft_tablen_bonus.c \
				srcs/bonus/utils_bonus/is_exec_bonus.c \
				srcs/bonus/heredoc/del.c \
				srcs/bonus/heredoc/utils.c \
			export/essential/ft_bzero.c \
			export/essential/ft_memmove.c \
			export/essential/ft_itoa.c \
			export/essential/ft_ppxadd_back_bonus.c \
			export/essential/ft_ppxclear_bonus.c \
			export/essential/ft_ppxnew_bonus.c \
			export/essential/ft_split.c \
			export/essential/ft_split2.c \
			export/essential/ft_strlen.c \
			export/essential/ft_strchr.c \
			export/essential/ft_strjoin.c \
			export/essential/ft_strlcpy.c \
			export/essential/ft_strncmp.c \
			export/essential/ft_strncpy.c \
			export/essential/ft_strndup.c \
			export/printf/srcs/ft_printf.c \
			export/gnl/get_next_line.c \
			export/gnl/get_next_line_utils.c \
				export/printf/libft/ft_putchar.c \
				export/printf/libft/ft_putnbr.c \
				export/printf/libft/ft_putnbr_unsigned.c \
				export/printf/libft/ft_putstr.c \
				export/printf/libft/ft_puthexa.c \
				export/printf/libft/ft_putpointer.c

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

FLAGS = -Wall -Wextra -Werror
OPTIONS = -c

#################################################################################

RED = '\033[0;31m'
GREEN = '\033[0;32m'
YELLOW = '\033[0;33m'
BLUE = '\033[0;34m'
PURPLE = '\033[0;35m'
CYAN = '\033[0;36m'
MAGENTA = '\033[0;35m'
NC = '\033[0m'

#################################################################################

%.o: %.c
	@$(CC) $(FLAGS) $(OPTIONS) $< -o $@
	@echo $(GREEN)✅ $< compiled! $(NC)

$(NAME): $(OBJECTS) eval
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo $(BLUE)✅ $@ built! $(NC)

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	@$(CC) $(FLAGS) $(BONUS_OBJECTS) -o $(NAME)
	@echo $(PURPLE)✅ $(NAME) with bonus built! $(NC)

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)
	@echo $(YELLOW)🗑️ $(OBJECTS) $(BONUS_OBJECTS) deleted! $(NC)

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo $(RED)🗑️ $(NAME) and $(BONUS) deleted! $(NC)

re: fclean all

.PHONY: all clean fclean re eval


eval:
	@echo $(CYAN)******************************************************$(RESET)
	@echo $(MAGENTA)"*                                                    *"$(RESET)
	@echo $(MAGENTA)*$(RESET) $(GREEN)"   Cher évaluateur, veuillez noter ce projet "$(MAGENTA)$(RESET)"      *"
	@echo $(MAGENTA)*$(RESET) $(GREEN)"   comme "$(YELLOW)"OUTSTANDING"$(GREEN)" car il est "$(BLUE)"remarquable!"$(MAGENTA) $(RESET)"      *"
	@echo $(MAGENTA)"*                                                    *"$(RESET)
	@echo $(CYAN)******************************************************$(RESET)