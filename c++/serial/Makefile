CC = g++
CFLAGS = -Wall

ifeq ($(OS), Windows_NT)
NAME = main.exe
else
NAME = main.out
endif

.PHONY: clean

$(NAME): main.cpp
	$(CC) $(CFLAGS) -o $(NAME) main.cpp

clean:
	rm -f *.obj $(NAME)

test:
	./$(NAME)
