// Assignment name  : ft_strncmp
// Expected files   : ft_strncmp.c
// Allowed functions: None

// Reproduce the behavior of strncmp (man strncmp).

// Prototype: int ft_strncmp(char *s1, char *s2, unsigned int n);


int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
	i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>

int main(void)
{
	char str1[] = "ZbbB";
	char str2[] = "ZaBb";

	printf("%i\n", ft_strncmp(str1, str2, 2));
}
