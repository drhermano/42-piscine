// Write a program that takes a string as argument and displays it
// without any non-alphabetical characters, followed by a newline.
// If no argument, display only a newline.

// Example:
// $> ./only_alphabet "abc123def"
// abcdef
// $> ./only_alphabet "Hello, World!"
// HelloWorld

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i;

		i = 0;
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
				write(1,&argv[1][i],1);
			i++;
		}
	}
	write (1,"\n",1);
}