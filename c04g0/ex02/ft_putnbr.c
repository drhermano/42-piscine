/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:52:17 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/11 08:07:44 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	longnb;

	longnb = nb;
	if (longnb < 0)
	{
		write(1, "-", 1);
		longnb = -longnb;
	}
	if (longnb >= 10)
	{
		ft_putnbr(longnb / 10);
	}
	write(1, &"0123456789"[longnb % 10], 1);
}

/* 
int main()
{
	int nb;

	nb = 1235;
	ft_putnbr(nb);
}
 */