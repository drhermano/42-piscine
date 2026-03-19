// Assignment name  : ft_str_is_uppercase
// Expected files   : ft_str_is_uppercase.c
// Allowed functions: None

// Returns 1 if string contains only uppercase alpha characters, 0 otherwise.
// Returns 1 if string is empty.

// Prototype: int ft_str_is_uppercase(char *str);

#include <stdio.h>
int ft_str_is_uppercase(char *str)
{
	int i = 0;
	int size = 0;

	while (str[size])
	{
	size++;
	}
	while (str[i] && str[i] >= 'A' && str[i] <= 'Z')
	{
	i++;
	}
	if (size <= i)
		return (1);
	else
		return (0);
}

#include <stdio.h>

int main(void)
{
	char str[] = " ";

	printf("%i\n", ft_str_is_uppercase(str));
}
