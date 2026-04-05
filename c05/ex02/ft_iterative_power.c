/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:42:29 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/13 19:35:43 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	x;

	x = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		x *= nb;
		power--;
	}
	return (x);
}

/* 
#include <stdio.h>
int main (void)
{
	printf("%i\n", ft_iterative_power(2, -1));
	printf("%i\n", ft_iterative_power(0, 0));
	printf("%i\n", ft_iterative_power(3, 1));
	printf("%i\n", ft_iterative_power(3, 3));
	printf("%i\n", ft_iterative_power(-3, 3));
}
 */