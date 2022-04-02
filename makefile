# All Targets
all: task0 t1a t1d t2

libs: c-lib

task0: count-words.c
	gcc -m32 -g -Wall -o count count-words.c

t1a: addresses.c
	gcc -m32 -g -Wall -o t1a addresses.c

t1d: t1d.c
	gcc -m32 -g -Wall -o t1d t1d.c

t2: t2.c
	gcc -m32 -g -Wall -o t2 t2.c


# task0.o: count-words.c
# 	gcc -g -Wall -m32 -ansi -c -o task0.o countwords.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o count t1a t1b t2
