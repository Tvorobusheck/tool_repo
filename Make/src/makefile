objects = main.o printFunc.o
CC = -O2 -march=native -std=c11

main: $(objects)
	gcc $(objects) $(CC) -o ../bin/test_work

main.o: main.c main.h
	gcc main.c -c $(CC) -o main.o
 
printFunc.o: printFunction.c main.h
	gcc printFunction.c -c $(CC) -o printFunc.o

clean:
	rm -f $(objects)