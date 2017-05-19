NAME = UnixEngine

CFLAGS = -Wall -Wextra -Werror

SRCS =	./engine/*.cpp

RM = rm -f

.PHONY: clean draw

all: draw

draw:
	g++ $(SRCS) ./apps/draw.cpp -o draw -std=c++11 -pthread

clean:
	$(RM) draw

re: clean all
