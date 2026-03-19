/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:30:11 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/13 19:35:47 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}

/* 
#include <stdio.h>
int main (void)
{
	printf("%i\n", ft_sqrt(-100));	
	printf("%i\n", ft_sqrt(0));
	printf("%i\n", ft_sqrt(1));
	printf("%i\n", ft_sqrt(2));
	printf("%i\n", ft_sqrt(4));
	printf("%i\n", ft_sqrt(9));
	printf("%i\n", ft_sqrt(81));
	printf("%i\n", ft_sqrt(100));
}
 */