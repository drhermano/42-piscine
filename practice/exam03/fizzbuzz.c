// Assignment name  : fizzbuzz
// Expected files   : fizzbuzz.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that writes a series of numbers of 1 to 100 on the output
// Standard, all separated by a Newline.

// If the number is a multiple of 3, the program must write 'Fizz' instead.

// If the number is a multiple of 5, the program must write 'Buzz' instead.

// If the number is a multiple of 3 and a multiple of 5, the program must write
// 'Fizzbuzz' instead.

// Exemple:

// $>./fizzbuzz
// 1
// 2
// fizz
// 4
// buzz
// fizz
// 7
// 8
// fizz
// buzz
// 11
// fizz
// 13
// 14
// fizzbuzz
// [...]
// 97
// 98
// fizz
// buzz
// $> 

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr (int n)
{
	// int i = 0;
	
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int main (void)
{
	int i = 1;

	while (i <= 100)
	{
		if (i > 0 && i % 3 == 0 && i % 5 == 0)
		{
			write(1, "fizzbuzz", 9);
			ft_putchar('\n');
		}		
		else if (i > 0 && i % 3 == 0)
		{
			write(1, "fizz", 5);
			ft_putchar('\n');
		}
		else if (i > 0 && i % 5 == 0)
		{
			write(1, "buzz", 5);
			ft_putchar('\n');
		}
		else
		{
			ft_putnbr(i);
			ft_putchar('\n');
		}
		i++;
	}
}


