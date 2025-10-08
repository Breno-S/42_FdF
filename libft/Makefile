NAME := libft.a

BUILD_DIR := obj

SRC_DIR := .
INC_DIR := .

SRCS := \
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

GNL_SRC_DIR := gnl
GNL_INC_DIR := gnl

GNL_SRCS := \
		get_next_line.c \
		get_next_line_utils.c
GNL_SRCS := $(addprefix $(GNL_SRC_DIR)/,$(GNL_SRCS))

FT_PRINTF_SRC_DIR := ft_printf
FT_PRINTF_INC_DIR := ft_printf

FT_PRINTF_SRCS := \
		ft_printf.c \
		print_funcs.c
FT_PRINTF_SRCS := $(addprefix $(FT_PRINTF_SRC_DIR)/,$(FT_PRINTF_SRCS))

OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o) \
		$(GNL_SRCS:$(GNL_SRC_DIR)/%.c=$(BUILD_DIR)/%.o) \
		$(FT_PRINTF_SRCS:$(FT_PRINTF_SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC := cc
CPPFLAGS := $(addprefix -I,$(INC_DIR)) $(addprefix -I,$(GNL_INC_DIR))
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule for GNL
$(BUILD_DIR)/%.o: $(GNL_SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Rule for FT_PRINTF
$(BUILD_DIR)/%.o: $(FT_PRINTF_SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Rule for base libft functions
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

re:
	@$(MAKE) fclean
	@$(MAKE)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

.PHONY: all re clean fclean
