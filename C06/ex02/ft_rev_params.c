/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 11:45:07 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/17 12:12:06 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	l;

	i = 1;
	l = ac - 1;
	while (i < ac)
	{
		j = 0;
		while (av[l][j])
		{
			ft_putchar(av[l][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		l--;
	}
}
