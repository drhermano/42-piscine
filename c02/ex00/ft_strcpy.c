/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:35:34 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/06 14:54:58 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

#include <stdio.h>

int main(void)
{
	char src[] = "ABC";
	char dest[] = "DFG";

	printf("dest before:%s\n", dest);
	ft_strcpy(dest, src);
	printf("dest after:%s\n", dest);

}
