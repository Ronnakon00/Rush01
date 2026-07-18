/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 05:09:13 by marvin            #+#    #+#             */
/*   Updated: 2026/07/18 05:09:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		read_data_a_organize_data(int *result, char *str);
void	grid_zero(int grid[4][4]);
void	print_grid(int grid[4][4]);
int		solve(int grid[4][4], int data[16], int row, int col);

int	main(int arg, char **data)
{
	int	datatouse[16];
	int	grid[4][4];

	if (arg != 2 || read_data_a_organize_data(datatouse, data[1]) != 16)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	///////////////show result after read_data_a_organize_data/////////////////
	// int j = 0;
	// while (j < 16)
	// {
	// 	char c = datatouse[j] + '0';
	// 	write (1, &c, 1);
	// 	j++;
	// }
	grid_zero(grid);
	if (solve(grid, datatouse, 0, 0) == 1)
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
