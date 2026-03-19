// Recebe uma string como um argumento
// se a string for um palindromo, display ela e depois uma nova linha.
// se nao, apenas uma nova linha

#include <unistd.h>
#include <stdio.h>
void	is_palindromo(char *str)
{
	int	count_str;
	int	count_b;
	int	count_c;
	char	b[50];

	count_str = 0;
	count_b = 0;
	count_c = 0;
	while(str[count_str])
		count_str++;
	count_str--;
	if (count_str % 2 == 1)
	{
		count_b = count_str / 2;
		while (count_c <= count_b)
		{
			b[count_c] = str[count_str];
			count_c++;
			count_str--;
		}
	}
	printf("%s %s",str, b);
}


int main (void)
{
		is_palindromo("ABBA");
}