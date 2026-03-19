// Returns 1 if string contains only printable characters, 0 otherwise.
// Returns 1 if string is empty.
// Printable = ASCII 32 to 126.

// Prototype: int ft_str_is_printable(char *str);

int ft_str_is_printable(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int main (void)
{
	char str[] = "abcdefghi";
	ft_str_is_printable(str);

	printf("%i\n", ft_str_is_printable(str));
}