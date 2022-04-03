#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char censor(char c) {
  if(c == '!')
    return '*';
  else
    return c;
}
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  int i;
  for (i = 0; i < array_length; i++)
  {
	  mapped_array[i] = (*f)(array[i]);
  }
  return mapped_array;
}

char encrypt(char c)
/* Gets a char c and returns its encrypted form by adding 2 to its value.
* If c is not between 0x41 and 0x7a it is returned unchanged */
{
	if (c >= 0x41 && c<= 0x7a)
		return c + 2;
	return c;
}

char decrypt(char c)
/* Gets a char c and returns its decrypted form by reducing 2 to its value. 
 * If c is not between 0x41 and 0x7a it is returned unchanged */
{
	printf("decrypt: %x\n", c);
	if (c >= 0x41 && c<= 0x7a)
		return c - 2;
	return c;
}

char dprt(char c)
/* dprt prints the value of c in a decimal representation followed by a 
 * new line, and returns c unchanged. */
{
	printf("%d\n", c);
}

char cprt(char c)
/* If c is a number between 0x41 and 0x7a, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('*') character. After printing, cprt returns the value of c unchanged. */
{
	if (c >= 0x41 && c<= 0x7a)
		printf("%d\n", c);
	else
		printf("*\n");
	return c;
}

char my_get(char c)
/* Ignores c, reads and returns a character from stdin using fgetc. */
{
	return fgetc(stdin);
}
char quit(char c) /* Gets a char c, and if the char is 'q', ends the program with exit code 0. Otherwise returns c. */
{
	if (c == 'q')
		exit(0);
	return c;
}

void print_menu(struct & menu)
{
	int i;
	for (i = 0; i < sizeof(menu)/sizeof(menu[0]); i++)
	{
		printf("%d) %s\n", i, menu[0]);
	}
	printf("Option: ");
}


void parse_input(int input, struct fun_desc* menu[])
{
	if (input >= 0 && input <= sizeof(menu)/sizeof(menu[0])) {
		printf("Within bounds");
	}
	else
	{
		printf("Not within bounds");
		exit(1);
	}
	

	
}

		
 
int main(int argc, char **argv){

	int base_len = 5;
	char* carray[base_len] = "";
	int input;
	struct fun_desc menu[] = { { "Cencor", cencor }, { "Encrypt", encrypt }, { "Decrypt", decrypt }, {"Print dec", dprt}, {"Print string", cprt}, {"Get String", my_get}, {"Quit", quit}, { NULL, NULL }};
	do
	{
		print_menu();
		input = fgetc(stdin);
		parse_input(input, &menu);
		carray = map(carray, base_len, menu[input][1])
	} while (true);
	




	char arr1[base_len];
	char* arr2 = map(arr1, base_len, my_get);
	char* arr3 = map(arr2, base_len, encrypt);
	char* arr4 = map(arr3, base_len, dprt);
	char* arr5 = map(arr4, base_len, decrypt);
	char* arr6 = map(arr5, base_len, cprt);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
}



