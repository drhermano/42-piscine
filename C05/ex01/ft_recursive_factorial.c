/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:32:06 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/13 19:35:39 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb -1));
}

/* 
#include <stdio.h>
int main (void)
{
	printf("%i\n", ft_recursive_factorial(-1));
	printf("%i\n", ft_recursive_factorial(0));
	printf("%i\n", ft_recursive_factorial(1));
	printf("%i\n", ft_recursive_factorial(2));
	printf("%i\n", ft_recursive_factorial(3));
	printf("%i\n", ft_recursive_factorial(4));
	printf("%i\n", ft_recursive_factorial(5));
	printf("%i\n", ft_recursive_factorial(6));
	printf("%i\n", ft_recursive_factorial(7));
	printf("%i\n", ft_recursive_factorial(8));
	printf("%i\n", ft_recursive_factorial(100));
}
 */