SRC = srcs/ft_map.c srcs/main.c srcs/ft_str.c srcs/ft_algo.c srcs/l9owatLmosa3ida.c srcs/ft_readstdin.c
OBJS = $(SRC:.c=.o)
TARGET = qsb
CC = gcc
INCLUDES = includes
FLAGS = -Wall -Werror -Wextra

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCLUDES)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(TARGET) -I$(INCLUDES)

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re:     fclean all

.PHONY: all clean fclean re
	
