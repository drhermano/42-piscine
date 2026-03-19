/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 10:21:12 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/04 19:42:40 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void)
{
	char letter;

	letter = 'z';
	while (letter >= 'a')
	{
		write(1,&letter,1);
		letter--;
	}
}

int main(void)
{
	ft_print_alphabet();
}



