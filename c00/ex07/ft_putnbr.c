/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:12:39 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/01 15:32:36 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

/*int	main(void)
{
	ft_putnbr(-554934);
	return (0);
}*/
