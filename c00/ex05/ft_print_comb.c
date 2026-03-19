/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 20:21:28 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/02 17:57:54 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	firstn;
	char	secondn;
	char	thirdn;

	firstn = '0';
	while (firstn <= '7')
	{
		secondn = firstn + 1;
		while (secondn <= '8')
		{
			thirdn = secondn + 1;
			while (thirdn <= '9')
			{
				write (1, &firstn, 1);
				write (1, &secondn, 1);
				write (1, &thirdn, 1);
				if (!(firstn == '7' && secondn == '8' && thirdn == '9'))
					write (1, ",", 1);
				thirdn++;
			}
			secondn++;
		}
		firstn++;
	}
}

// int	main(void)
// {
// 	ft_print_comb();
// 	return (0);
// }
