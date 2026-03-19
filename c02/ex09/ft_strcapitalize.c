/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:48:38 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/19 09:55:17 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		i++;
		}
	return (str);
}

#include <stdio.h>

int main()
{
	char str[] = "isso, e iSSO. devem estar em lowercase+tambéM ";
	printf("%s\n", ft_strcapitalize(str));
}