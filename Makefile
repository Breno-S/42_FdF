NAME        := fdf
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
AR          := ar rcs
RM          := rm -f

INC_DIR		:= .

MLX_DIR		:= minilibx-linux
MLX			:= $(MLX_DIR)/libmlx.a

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

MANDATORY_DIR := mandatory
BONUS_DIR     := bonus
BUILD_DIR     := obj

INC_MANDATORY := $(INC_DIR) $(MANDATORY_DIR) $(LIBFT_DIR) $(MLX_DIR)
INC_BONUS     := $(INC_DIR) $(BONUS_DIR) $(LIBFT_DIR) $(MLX_DIR)

MANDATORY_SRCS := \
				draw_line.c \
				draw_map.c \
				env_utils.c \
				fdf_utils.c \
				main.c \
				parse_map.c

BONUS_SRCS := \
				draw_line_bonus.c \
				draw_map_bonus.c \
				env_utils_bonus.c \
				fdf_utils_bonus.c \
				input_keyboard_bonus.c \
				input_mouse_bonus.c \
				main_bonus.c \
				parse_map_bonus.c \
				projection_bonus.c \
				transform_bonus.c

MANDATORY_SRCS := $(addprefix $(MANDATORY_DIR)/,$(MANDATORY_SRCS))
BONUS_SRCS     := $(addprefix $(BONUS_DIR)/,$(BONUS_SRCS))

MANDATORY_OBJS := $(addprefix $(BUILD_DIR)/,$(notdir $(MANDATORY_SRCS:.c=.o)))
BONUS_OBJS     := $(addprefix $(BUILD_DIR)/,$(notdir $(BONUS_SRCS:.c=.o)))

LDLIBS		:= -lmlx -lft -lX11 -lXext -lm
LDFLAGS		:=  -L $(LIBFT_DIR) -L $(MLX_DIR)

all: $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_OBJS)
	$(CC) -o $(NAME) $(BONUS_OBJS) $(LDFLAGS) $(LDLIBS)

$(NAME): $(LIBFT) $(MLX) $(MANDATORY_OBJS)
	$(CC) -o $(NAME) $(MANDATORY_OBJS) $(LDFLAGS) $(LDLIBS)

# Mandatório
$(BUILD_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(addprefix -I,$(INC_MANDATORY)) $(CFLAGS) -c $< -o $@

# Bônus
$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(addprefix -I,$(INC_BONUS)) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
