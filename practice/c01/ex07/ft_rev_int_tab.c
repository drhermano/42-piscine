/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:39:11 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/04 15:56:19 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	size--;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		i++;
		size--;
	}
}

#include <stdio.h>

int main(void)
{
	int tab[5] = {1,2,3,4,5};
	int size = 5;
	ft_rev_int_tab(tab, size);

	int i;
	i = 0;
	while (i < size)
	{
	printf("%i\n",tab[i]);
	i++;
	}
}


// • Crie uma função que inverta um array de inteiros dado (o primeiro elemento se
// torna o último, e assim por diante).
// • A função recebe dois argumentos: um ponteiro para um int e o número de elementos
// no array.
// • A função deve ser prototipada da seguinte forma: