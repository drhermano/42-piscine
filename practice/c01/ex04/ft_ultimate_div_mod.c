/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:35:43 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/04 20:45:14 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_ultimate_div_mod(int *a, int *b);
{
	int temp;
	
	temp = a;
	a = a / b;
	b = temp % b;

}

int main(void)
{
	int a;
	int b;

	a = 10;
	b = 2;

}

// • Esta função divide o valor apontado por ‘a’ pelo valor apontado por ‘b’. O resultado
// da divisão é armazenado no inteiro apontado por ‘a’, enquanto o resto é armazenado
// no inteiro apontado por ‘b’.