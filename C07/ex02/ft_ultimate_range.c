/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:54:28 by smachado          #+#    #+#             */
/*   Updated: 2026/03/18 19:15:42 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	i = 0;
	len = max - min;
	if (len <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(len * 4);
	if (!*range)
	{
		return (-1);
	}
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *arr;
// 	int size;
// 	int i;

// 	size = ft_ultimate_range(&arr, 2, 8);
// 	if (size <= 0)
// 		return (1);
// 	printf("%d\n\n ", size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}

// 	free(arr);
// }
