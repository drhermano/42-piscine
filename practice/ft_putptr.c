
#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

void	ft_putchar(char c);
void 	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_puthex(unsigned long n);
void 	ft_putptr(void *ptr);
int 	main (void)
	{
		int number;

		number = 1;

		int *pointer1 = &number;
		int **pointer2 = &pointer1;
		int ***pointer3 = &pointer2;		
		int ****pointer4 = &pointer3;
		int *****pointer5 = &pointer4;
		int ******pointer6 = &pointer5;
		int *******pointer7 = &pointer6;
		int ********pointer8 = &pointer7;
		int *********nbr = &pointer8;

		ft_ultimate_ft(nbr);
		
		ft_putstr("'Number' has the address ");
		ft_putptr(&number);
		ft_putstr(" and the value ");
		ft_putnbr(number);
		ft_putchar('\n');
		ft_putstr("pointer1 points to same address of 'Number' ");
		ft_putptr(pointer1);
		ft_putstr(" and has the same value ");
		ft_putnbr(*pointer1);
		ft_putchar('\n');
		ft_putstr("\nAfter ft_ultimate_ft:\n");

		ft_ultimate_ft(nbr);

		ft_putstr("Pointer 'nbr' remains pointing to address ");
		ft_putptr(nbr);
		ft_putstr(", but now has the value ");
		ft_putnbr(*********nbr);
		ft_putchar('\n');

		ft_putstr("'Number' remains at address ");
		ft_putptr(&number);
		ft_putstr(", but now has the value ");
		ft_putnbr(number);
		ft_putchar('\n');

	}

void	ft_puthex(unsigned long n)
{
	char *base;
	base = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16);
	ft_putchar(base[n % 16]);
}

void 	ft_putptr(void *ptr)
	{
		unsigned long addr;

		addr = (unsigned long)ptr;
		ft_putstr("0x");
		ft_puthex(addr);
	}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	nblong;

	nblong = nb;
	if (nblong < 0)
	{
		ft_putchar('-');
		nblong = -nblong;
	}
	if (nblong >= 10)
	{
		ft_putnbr(nblong / 10);
	}
	ft_putchar(nblong % 10 + '0');
}
