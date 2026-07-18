/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 13:19:16 by marvin            #+#    #+#             */
/*   Updated: 2026/07/18 13:19:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom 
//  row1left row2left row3left row4left row1right row2right row3right row4right"

///////////////////past of rules/////////////////////
int	count_forward(int *line)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_backward(int *line)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_row(int grid[4][4], int data[16], int row)
{
	int	i;
	int	row_line[4];
	int	count_left;
	int	count_right;

	i = 0;
	while (i < 4)
	{
		row_line[i] = grid[row][i];
		i++;
	}
	count_left = count_forward(row_line);
	count_right = count_backward(row_line);
	if (count_left != data[8 + row] || count_right != data[12 + row])
		return (0);
	return (1);
}

int	check_col(int grid[4][4], int data[16], int col)
{
	int	i;
	int	col_line[4];

	i = 0;
	while (i < 4)
	{
		col_line[i] = grid[i][col];
		i++;
	}
	if (count_forward(col_line) != data[col])
		return (0);
	if (count_backward(col_line) != data[4 + col])
		return (0);
	return (1);
}

///////////////////past of redundant/////////////////////
int	is_not_redundant(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

///////////////////past of maxsize///////////////////
int	is_max(int grid[4][4], int data[16], int row, int col)
{
	if (col == 3)
	{
		if (check_row(grid, data, row) == 0)
			return (0);
	}
	if (row == 3)
	{
		if (check_col(grid, data, col) == 0)
			return (0);
	}
	return (1);
}

////////////////////past of random//////////////////////
int	solve(int grid[4][4], int data[16], int row, int col)
{
	int	num;

	if (row == 4)
		return (1);
	if (col == 4)
		return (solve(grid, data, row + 1, 0));
	num = 1;
	while (num <= 4)
	{
		if (is_not_redundant(grid, row, col, num) == 1)
		{
			grid[row][col] = num;
			if (is_max(grid, data, row, col) == 1)
			{
				if (solve(grid, data, row, col + 1) == 1)
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}