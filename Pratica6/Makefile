all:
	gcc -c ordenacao.c -Wall
	gcc -c pratica6.c -Wall
	gcc ordenacao.o pratica6.o -o exe

run_1:
	make
	./exe < 1.in > out.out
	diff out.out 1.out

run_2:
	make
	./exe < 2.in > out.out
	diff out.out 2.out

run_3:
	make
	./exe < 3.in > out.out
	diff out.out 3.out

clear:
	rm *.o out.out exe