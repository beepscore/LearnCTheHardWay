CFLAGS=-Wall -g -DNDEBUG

clean:
	rm -f ex1
	rm -f ex3
	rm -f ex4
	rm -f ex5
	rm -f ex6
	rm -f ex7
	rm -f ex8
	rm -f ex9
	rm -f ex10
	rm -f ex11
	rm -f ex12
	rm -f ex13
	rm -f ex13b
	rm -f ex14
	rm -f ex15
	rm -f ex16
	rm -f ex17
	rm -f ex20
	rm -f ex22.o
	rm -f ex22_main
	rm -r ex22_main.dSYM

ex22_main: ex22.o

all:
	make ex1
	make ex3
	make ex4
	make ex5
	make ex6
	make ex7
	make ex8
	make ex9
	make ex10
	make ex11
	make ex12
	make ex13
	make ex13b
	make ex14
	make ex15
	make ex16
	make ex17
	make ex20
