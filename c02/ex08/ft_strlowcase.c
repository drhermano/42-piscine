/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:48:01 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/05 10:12:38 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>
//
// int main (void)
// {
// 	char str[] = "abcDef";
// 	ft_strlowcase(str);
//	
// 	printf("%s\n", ft_strlowcase(str));
//
// }