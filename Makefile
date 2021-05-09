CC = gcc
CFLAGS = -Wall -Wextra


a.out : leak_detector.c main.c unit.c
	$(CC) $(CFLAGS) $^ -o $@  
 
clean:
	rm a.out
