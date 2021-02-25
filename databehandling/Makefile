CC = gcc
CFLAGS = -O -std=gnu99 -Wall
LDLIBS = -lm

.PHONEY: clean cat plot 

main: main.o                            
	$(CC) -o main main.o  $(LDLIBS) 

main.o: main.c 
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) 

clean:                          
	$(RM) main main.o out.txt ### clean up the directory
	
cat:
	cat out.txt
	
plot:
	export DISPLAY=:0 
	gnuplot-x11 -e "filename = 'out.txt'" settings.plg
	