NAME = UnixEngine

CFLAGS = -Wall -Wextra -Werror

SRCS =	./engine/engine.cpp \
		./engine/canvas.cpp \
		./engine/view.cpp

RM = rm -f

.PHONY: fclean all

all: fclean

draw:
	g++ $(SRCS) ./apps/draw.cpp -o draw -std=c++11

clean:
	$(RM) draw

fclean: clean
	$(RM) draw

re: fclean all
