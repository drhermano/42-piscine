// Write a program that takes three arguments: an int, an operator,
// and another int. Displays the result, followed by a newline.
// If wrong number of args, display nothing (just newline).

// Operators: +  -  *  /  %

// Example:
// $> ./do_op 1 + 1
// 2
// $> ./do_op 10 / 3
// 3

#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int signal = 1;
	int sum = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (signal * sum);
}

int ft_cmp(char *a, char *b)
{
	int i = 0;

	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

void itoa(int n)
{
	long int nb = n;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * nb;
	}
	if (nb >= 10)
	{
		itoa(nb / 10);
	}
	write (1, &"0123456789"[nb % 10],1);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		int result;
		result = 0;

		if (ft_cmp(argv[2], "+") == 0)
			result = ft_atoi(argv[1]) + ft_atoi(argv[3]);
		if (ft_cmp(argv[2], "-") == 0)
			result = ft_atoi(argv[1]) - ft_atoi(argv[3]);
		if (ft_cmp(argv[2], "*") == 0)
			result = ft_atoi(argv[1]) * ft_atoi(argv[3]);
		if (ft_cmp(argv[2], "/") == 0 && ft_cmp(argv[3],"0") != 0)
			result = ft_atoi(argv[1]) / ft_atoi(argv[3]);
		if (ft_cmp(argv[2], "%") == 0 && ft_cmp(argv[3],"0") != 0)
			result = ft_atoi(argv[1]) % ft_atoi(argv[3]);

		itoa(result);
	}
	write(1,"\n",1);
}
