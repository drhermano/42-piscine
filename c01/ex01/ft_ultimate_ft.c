/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:44:08 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/19 13:27:36 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int 	main (void)
	{
		int number;

		number = 1;

		int *pointer1 = &number;
		int **pointer2 = &pointer1;
		int ***pointer3 = &pointer2;		
		int ****pointer4 = &pointer3;
		int *****pointer5 = &pointer4;
		int ******pointer6 = &pointer5;
		int *******pointer7 = &pointer6;
		int ********pointer8 = &pointer7;
		int *********nbr = &pointer8;

		ft_ultimate_ft(nbr);
	}
