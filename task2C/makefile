# All Targets
all: menu

menu: menu_map.c
	gcc -m32 -g -Wall -o menu menu_map.c

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean:
	rm -f *.o menu
