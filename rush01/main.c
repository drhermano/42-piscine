/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 11:12:05 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/07 18:17:23 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void);
int		is_correct_params(char **argv);

int	main(int argc, char **argv)
{
	if (argc != 2 || !is_correct_params(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}

int	is_correct_params(char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4' && i % 2 == 0)
			count++;
		else if (argv[1][i] != ' ')
			return (0);
		i++;
	}
	if (count == 16 && i == 31)
		return (1);
	return (0);
}
