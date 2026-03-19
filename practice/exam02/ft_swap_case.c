/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:22:25 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/06 08:03:25 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_swap_case(char *src)

{
	int	i;

	i = 0;
	while (src[i])
	{
		if(src[i] >='a' && src[i] <= 'z')
			src[i] -=32;
		else if(src[i] >='A' && src[i] <= 'z')
			src[i] +=32;
		// src[i] = src[i] + 32 ;
		i++;
	}
	return (src);
}

#include <stdio.h>
int main (void)
{
	char ptr[] = "test, TEST";
	printf("%s",ft_swap_case(ptr));
	return(0);
}