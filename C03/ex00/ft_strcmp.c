/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:16:03 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/10 15:16:24 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char *s1 = "Z";
// 	char *s2 = "Á";

// 	ft_strcmp(s1, s2);

// 	printf("%d\n", strcmp(s1, s2));
// 	printf("%d\n", ft_strcmp(s1, s2));
// }