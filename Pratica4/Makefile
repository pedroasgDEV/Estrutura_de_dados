all:
	gcc -c lista.c -Wall
	gcc -c pilha.c -Wall
	gcc -c pratica4.c -Wall
	gcc lista.o pilha.o pratica4.o -o exe

run1:
	make
	./exe < 1.in > test.out
	diff test.out 1.out

run2:
	make
	./exe < 2.in > test.out
	diff test.out 2.out

clear:
	rm *.o exe test.out