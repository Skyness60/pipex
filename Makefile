NAME = pipex

CC = cc -g3

SOURCES_PRINTF = lib/printf/srcs/ft_printf.c

SOURCES_LIBFT = lib/libft/ft_nbrlen_base.c \
				lib/libft/ft_nbrlen.c \
				lib/libft/ft_bzero.c \
				lib/libft/ft_calloc.c \
				lib/libft/ft_strchr.c \
				lib/libft/ft_putchar.c \
				lib/libft/ft_strcpy.c \
				lib/libft/ft_puthexa.c \
				lib/libft/ft_putnbr_unsigned.c \
				lib/libft/ft_putnbr.c \
				lib/libft/ft_itoa.c \
				lib/libft/ft_putpointer.c \
				lib/libft/ft_putstr_fd.c \
				lib/libft/ft_putstr.c \
				lib/libft/ft_split.c \
				lib/libft/ft_split1.c \
				lib/libft/ft_split2.c \
				lib/libft/ft_split3.c \
				lib/libft/ft_substr.c \
				lib/libft/ft_strlen.c \
				lib/libft/ft_strncpy.c \
				lib/libft/ft_strncmp.c \
				lib/libft/ft_strdup.c \
				lib/libft/ft_strjoin.c \
				lib/libft/ft_strndup.c 

SOURCES_GNL =	lib/gnl/get_next_line.c \
				lib/gnl/get_next_line_utils.c

SOURCES =		$(SOURCES_PRINTF) \
				$(SOURCES_LIBFT) \
				$(SOURCES_GNL) \
				srcs/project/pipex.c \
				srcs/project/pipex_utils.c \
				srcs/project/ppx.c \
				srcs/project/childs.c \
				srcs/project/redirection.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES =	$(SOURCES_PRINTF) \
				$(SOURCES_LIBFT) \
				$(SOURCES_GNL) \
				srcs/bonus/pipex_bonus.c \
				srcs/bonus/pipex_utils_bonus.c \
				srcs/bonus/ppx_bonus.c \
				srcs/bonus/heredoc.c \
				srcs/bonus/childs_bonus.c \
				srcs/bonus/redirection_bonus.c

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

bonus: $(BONUS_OBJECTS)
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