/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:07:36 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/13 19:35:45 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, --power));
}

/* 
#include <stdio.h>

int main (void)
{
	printf("%i\n", ft_recursive_power(2,-1));
	printf("%i\n", ft_recursive_power(0,0));
	printf("%i\n", ft_recursive_power(3,1));
	printf("%i\n", ft_recursive_power(3,3));
	printf("%i\n", ft_recursive_power(-3,3));
}
 */