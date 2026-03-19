/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:53:58 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/07 15:33:05 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;

}

// int	main(void)
// {
// 	int a;
// 	int b;

// 	a = 5;
// 	b = 20;
// 	ft_ultimate_div_mod(&a, &b);
// }
