mygrep: main.o findsubstr.o readline.o
	gcc -o mygrep main.o findsubstr.o readline.o
main.o: main.c findsubstr.h readline.h
	gcc -c main.c
findsubstr.o: findsubstr.c findsubstr.h
	gcc -c findsubstr.c
readline.o: readline.c readline.h
	gcc -c readline.c
clean:
	rm -f mygrep *.o
