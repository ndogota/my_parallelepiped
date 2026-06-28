CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c11
NAME    = parallelepiped
OBJ     = my_parallelepiped.o my_tools.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c my_tools.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(NAME)

.PHONY: all clean
