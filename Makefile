TARGET=test
CC = gcc
CFLAGS = -Wall

#LIBS = -l pthread -l dl
LIBS = 

#SOURCE_C=$(wildcard *.c)
SOURCE_C = leak_detector.c test.c

#将变量SOUTCE_C的所有*.c改成*.o,赋值给变量OBJECT_O
#replace *.c to *.o from variable SOUTCE_C, and get the name string to variable OBJECT_O
#OBJECT_O=$(SOURCE_C:.c=.o)
OBJECT_O=$(SOURCE_C:%.c=%.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@  
 
$(TARGET): $(OBJECT_O)
#	$(CC) $(OBJECT_O) -o $(TARGET)
	$(CC) ${CFLAGS} $(OBJECT_O) $(LIBS) -o $@
	@echo "******success*******"
 

clean:
	rm *.o -rf
	rm $(TARGET).exe $(TARGET)  -rf
