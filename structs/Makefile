CC = gcc
CFLAGS = -O -std=gnu11
LDLIBS = -lm

.PHONEY: clean cat

main: main.o                            
	$(CC) -o main main.o  $(LDLIBS) 

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) 

clean:                          
	$(RM) main main.o out.txt ### clean up the directory
	
cat:
	cat out.txt
