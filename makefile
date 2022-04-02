# All Targets
all: task0

libs: c-lib

task0: count-words.c
	gcc -m32 -g -Wall -o count count-words.c

# task0.o: count-words.c
# 	gcc -g -Wall -m32 -ansi -c -o task0.o countwords.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o count
