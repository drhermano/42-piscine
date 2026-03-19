/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:37:13 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/11 08:07:46 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/* 
#include <stdio.h>

int main()
{
	char str[] = "This have 24 chars in it";
	ft_strlen(str);
	
	printf("%i\n",ft_strlen(str));
	
}
 */