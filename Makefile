NAME = UnixEngine

SRCS =	./engine/*.cpp

.PHONY: clean draw

all: draw

draw:
	-@ g++ $(SRCS) ./apps/draw.cpp -o draw -std=c++11 -pthread

tests:
	-@ sh run.sh

clean:
	-@ rm -f draw

re: clean all
