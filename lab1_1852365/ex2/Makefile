main: main.c sub.o sum.o
	g++ -o main main.c sub.o sum.o
sub.o: sub.c sub.h
	g++ -c sub.c
sum.o: sum.c sum.h
	g++ -c sum.c
clean: 
	rm main sub.o sum.o