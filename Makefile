CC=g++
CFLAGS= -std=c++11 -Wall
SRC = pairs_with_diff.cpp

build: $(SRC)
	$(CC) -o pairs $(SRC) -$(CFLAGS)

run: pairs
	./pairs

clean:
	rm -rf pairs
