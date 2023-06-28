CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic

SRCS = main.c matrix.c matrix_operations.c
OBJS = $(SRCS:.c=.o)
TARGET = MatrixMagic

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
