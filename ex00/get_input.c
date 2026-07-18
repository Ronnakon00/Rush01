/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:58:15 by marvin            #+#    #+#             */
/*   Updated: 2026/07/18 14:58:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	read_data_a_organize_data(int *result, char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (count >= 16)
				break ;
			result[j] = str[i] - '0';
			j++;
			count++;
			if (str[i + 1] != ' ')
				break ;
		}
		i++;
	}
	return (count);
}

void	grid_zero(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	digit;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			digit = grid[i][j] + '0';
			write(1, &digit, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}