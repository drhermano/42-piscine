// Reproduce the behavior of strncpy (man strncpy).

// Prototype: char *ft_strncpy(char *dest, char *src, unsigned int n);

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i  = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>


int main()
{
	char dest[] = "12345";
	char src[] = "6789";
	ft_strncpy(dest, src, 6);
	printf("%s\n",ft_strncpy(dest, src, 6));
	printf("%s\n",strncpy(dest, src, 6));

}