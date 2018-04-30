CC =			gcc
EXEC =			filler.filler
SRC_DIR =		./src/
OBJ_DIR =		./obj/
HEADER_DIR =	./include/
LIBFT_DIR = 	./libft/
LIBFT =			$(LIBFT_DIR)libft.a
CFLAGS =		-Wall -Werror -Wextra
DEBUG_FLAGS =	-fsanitize=address -g
ARFLAGS =		-rcs
CFILES =		main init parsing reset piece play
SRC =			$(CFILES:%=$(SRC_DIR)%.c)
OBJ =			$(CFILES:%=$(OBJ_DIR)%.o)

all: $(EXEC)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(EXEC): $(LIBFT) $(OBJ)
	#$(CC) $(SRC_DIR)main.c $(SRC) -I$(HEADER_DIR) -L./ -lftprintf -o $@ #$(CFLAGS) #$(DEBUG_FLAGS)
	$(CC) $(SRC) -I$(HEADER_DIR) libft/libft.a -o $@ $(CFLAGS) $(DEBUG_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo clean $@ Done !

fclean:	clean
	rm -f $(EXEC)
	@make -C $(LIBFT_DIR) fclean
	@echo fclean $@ Done !

re:		fclean all

.PHONY: clean fclean re
.SUFFIXES:
