
CC = gcc
shop : main.c manager.o
	$(CC) -o $@ $^
d_shop : main.c manager.o
	$(CC) -g $^ -DDEBUG  -o $@
manager.o : manager.c manager.h
	$(CC) -c manager.c -o manager.o
clean : 
	rm *.o *.txt shop

