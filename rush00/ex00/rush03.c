/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drocha-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:31:05 by drocha-h          #+#    #+#             */
/*   Updated: 2026/03/01 20:49:27 by drocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush_lines(int column, int line);
void	rush_columns(int columns, char first, char between, char last);

void	rush(int x, int y)
{
	int	column;
	int	line;

	column = x;
	line = y;
	if (column < 1 || line < 1 || column > 300 || line > 300)
	{
		write(1, "Column and line must be between 1 and 300.\n", 44);
		return ;
	}
	rush_lines(column, line);
}

void	rush_lines(int column, int line)
{
	int	count_lines;

	count_lines = 1;
	while (count_lines <= line)
	{
		if (count_lines == 1)
			rush_columns(column, 'A', 'B', 'C');
		else if (count_lines == line)
			rush_columns(column, 'A', 'B', 'C');
		else
			rush_columns(column, 'B', ' ', 'B');
		count_lines++;
	}
}

void	rush_columns(int columns, char first, char between, char last)
{
	int	count_columns;

	count_columns = 1;
	while (count_columns <= columns)
	{
		if (count_columns == 1)
			ft_putchar(first);
		else if (count_columns == columns)
			ft_putchar(last);
		else
			ft_putchar(between);
		count_columns++;
	}
	ft_putchar('\n');
}
