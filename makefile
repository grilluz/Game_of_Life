CC = gcc

CFLAGS = -g -Wall -std=c99
TARGET = bin/game_of_life
IDIR = -Iinclude/
OBJS = build/game_of_life.o 
SRC = src/game_of_life.c 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ src/main.c -o $@ $(IDIR)

$(OBJS): $(SRC) 
	$(CC) -c $(CFLAGS) $< $(IDIR) -o $(OBJS)

clean: 
	rm -f $(TARGET) build/*.o