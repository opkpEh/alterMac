opt=-O3 -Wall -std=c2x

all: clean alterMac

alterMac: alterMac.o
	cc ${opt} $^ -o $@

alterMac.o: alterMac.c
	cc ${opt} -c $^

clean:
	rm -f alterMac *.o
