all:
	gcc -c ordenacao.c -Wall
	gcc -c pratica5.c -Wall
	gcc ordenacao.o pratica5.o -o exe

run_1:
	make
	./exe < 1.in > test.out
	diff test.out 1.out

run_2:
	make
	./exe < 2.in > test.out
	diff test.out 2.out

clear:
	rm *.o exe test.out


