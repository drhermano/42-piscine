/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:51:16 by smachado          #+#    #+#             */
/*   Updated: 2026/03/18 19:15:31 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	len;
	int	i;

	i = 0;
	len = max - min;
	ptr = malloc(len * 4);
	if (min >= max)
		return (0);
	while (min < max)
	{
		ptr[i] = min;
		min++;
		i++;
	}
	return (ptr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	*arr;
// 	int	min;
// 	int	max;
// 	int	i;

// 	max = 10;
// 	min = 2;
// 	i = 0;
// 	arr = ft_range(min, max);
// 	if (arr == NULL)
// 		return (1);

// 	while (arr[i])
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}

// 	free(arr);
// 	return (0);
// }
