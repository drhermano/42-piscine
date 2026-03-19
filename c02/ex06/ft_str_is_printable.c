/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:19:33 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/05 13:04:43 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 32 && str[i] <= 126)))
			return (0);
		i++;
	}
	return (1);
}

/* 
#include <stdio.h>

int main(void)
{
	char *str = "thisisaod netest";
	ft_str_is_printable(str);
	printf("%s and %d\n", str, ft_str_is_printable(str));
}
 */