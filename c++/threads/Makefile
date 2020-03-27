CC = g++
CFLAGS = -pthread -Wall

ifeq ($(OS), Windows_NT)
NAME = main.exe
else
NAME = main.out
endif

$(NAME): main.cpp
	$(CC) $(CFLAGS) -o $(NAME) main.cpp

test: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)

.PHONY: clean
