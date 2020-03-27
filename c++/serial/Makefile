CC = g++
CFLAGS = -Wall

ifeq ($(OS), Windows_NT)
NAME = main.exe
else
NAME = main.out
endif

$(NAME): main.cpp
	$(CC) $(CFLAGS) -o $(NAME) main.cpp

clean:
	rm -f $(NAME)

test: $(NAME)
	./$(NAME)

.PHONY: clean
