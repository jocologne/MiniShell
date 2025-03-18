CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft/includes
LDFLAGS = -lreadline -Llibft -lft
TARGET = minishell
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT_REPO = https://github.com/jocologne/libft.git

all: $(LIBFT) $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ_DIR)/*.o $(TARGET)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(LIBFT_DIR)

re: fclean all

run: all
	@./$(TARGET)

rerun: re
	@./$(TARGET)

.PHONY: all clean fclean re