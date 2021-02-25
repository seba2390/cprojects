CFLAGS = -Wall -Werror -O1
CFLAGS += $(shell gsl-config --cflags)
LDLIBS += $(shell gsl-config --libs)
CC = gcc

.PHONEY:default

default: out.txt out.png

out.png: out.txt Makefile
	echo '\
	set terminal png size 1280,800;\
	set output "$@";\
	set size 1,1 ;\
	set key top right;\
	set tics out;\
	set xlabel "Growth rate";\
	set xzeroaxis linetype -1 linewidth 2.5;\
	set yzeroaxis linetype -1 linewidth 2.5;\
	set ylabel "Popsize at equilibrium";\
	set title "Bifurcation diagram of logistic growth";\
	set grid ;\
	set xrange [-0.1:4.1];\
	set yrange [-0.1:1.1];\
	plot \
	 "$<" using 1:2 with points pointtype 7 pointsize 0.01 title "Popsize at equilibrium"\
	' | gnuplot

out.txt: main
	./$< > $@

# Same as:
#	./main > out.txt

main:main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o main main.c $(LDLIBS)

.PHONEY:clean
clean:
	$(RM) out* main 

.PHONEY:show 
show:
	eog out.png

.PHONEY:test
test:
	echo CFLAGS
	echo $(CFLAGS)
	echo $(LDLIBS)