// Recebe uma string como um argumento
// se a string for um palindromo, display ela e depois uma nova linha.
// se nao, apenas uma nova linha

// arara

int ft_comp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] || s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char ft_rev(char *s1)
{
	int i = 0;
	int j = 0;
	char temp;

	while (s1[i])
	{
		i++;
	}
	i -= 1;
	while (i < i / 2 )
	{
		temp = s1[i];
		s1[i] = s1[j];
		s1[j] = temp;
		i++;
		j--;
	}
	return (*s1);
}

#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
	if (ac == 2)
	{
		char av1[] = av[1];
		printf("%s\n", ft_rev(&av1));
	}
	write (1, "\n", 1);
	return (0);
}