CC = gcc
CFLAGS = -Wall -Wextra


a.out : leak_detector.c test.c
	$(CC) $(CFLAGS) $^ -o $@  
 
clean:
	rm a.out
