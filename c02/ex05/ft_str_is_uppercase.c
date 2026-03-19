/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:27:47 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/10 13:51:41 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/* 
#include <stdio.h>

int main(void)
{
	char *str = "thisisaonetest";
	ft_str_is_uppercase(str);
	printf("%s and %d\n", str, ft_str_is_uppercase(str));
}
 */