CC=gcc
TARGET=cal.exe
SRCS=cal.c quadratic.c sum.c triples.c  

OBJS = $(SRCS:.c=.o)

$(TARGET):$(OBJS)
	$(CC) -Wall -std=gnu99 -o  $@ $^ -lm
clean:
	rm -rf $(TARGET) $(OBJS)
# %.o:%.c
# 	$(CC) -Wall -std=gnu99 -o $@ -c $< -lm