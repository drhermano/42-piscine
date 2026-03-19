/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:21:14 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/13 19:36:03 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	x;

	x = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		x *= nb;
		nb--;
	}
	return (x);
}

/* 
#include <stdio.h>
int main(void)
{
	printf("%i\n", ft_iterative_factorial(-1));
	printf("%i\n", ft_iterative_factorial(0));
	printf("%i\n", ft_iterative_factorial(1));
	printf("%i\n", ft_iterative_factorial(2));
	printf("%i\n", ft_iterative_factorial(3));
	printf("%i\n", ft_iterative_factorial(4));
	printf("%i\n", ft_iterative_factorial(5));
	printf("%i\n", ft_iterative_factorial(6));
	printf("%i\n", ft_iterative_factorial(7));
	printf("%i\n", ft_iterative_factorial(8));
	printf("%i\n", ft_recursive_factorial(100));
}

 */