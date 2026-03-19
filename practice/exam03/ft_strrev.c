// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	int i = ft_strlen(str);
	int j = 0;
	char	temp;

	i -= 1;
	while (i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "abcdefghiklmnopqrstuv";
// 	printf("%s\n", ft_strrev(s));
// }


// int ft_strcomp(char *str1, char *str2)
// {
// 	int i = 0;
// 	while (!(str1[i] == str2[i]))
// 		i++;
// 	return (str1[i] - str2[i]);
// }