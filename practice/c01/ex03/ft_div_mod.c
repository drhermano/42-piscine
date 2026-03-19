/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:39:32 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/04 19:44:41 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 10;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("%i\n", div);
	printf("%i\n", mod);
}

// Esta função divide ‘a’ por ‘b’ e armazena o resultado no inteiro apontado por ‘div’.
// Ela também armazena o resto da divisão de ‘a’ por ‘b’ no inteiro apontado por
// ‘mod’.

