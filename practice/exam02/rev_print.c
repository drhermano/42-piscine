// Assignment name  : rev_print
// Expected files   : rev_print.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a string and displays the string in reverse
// order followed by the newline.
// Its prototype is constructed like this : 
//   char *ft_rev_print (char *str)
// It must return its argument

// Examples:

// $> ./rev_print "zaz" | cat -e
// zaz$
// $> ./rev_print "dub0 a POIL" | cat -e
// LIOP a 0bud$
// $> ./rev_print | cat -e
// $

#include <unistd.h>

char *ft_rev_print (char *str)
{
	int size = 0;
	while (str[size])
	{
		size++;
	}
	size = size - 1;
	int i = 0;
	int temp = 0;
	while (size > i)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		size--;
		i++;
	}
	return (str);
}

#include <stdio.h>

int main (void)
{
	char str[] = "abcdefghi sdsdsd";
	printf("%s\n", ft_rev_print(str));
}