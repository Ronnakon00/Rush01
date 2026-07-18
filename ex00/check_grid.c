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
	int	count_left;
	int	count_right;

	count_left = count_forward(grid[row]);
	count_right = count_backward(grid[row]);
	if (count_left != data[8 + row] || count_right != data[12 + row])
		return (0);
	return (1);
}

int	check_col(int grid[4][4], int data[16], int col)
{
	int	i;
	int	col_line[4];
	int	count_up;
	int	count_down;

	i = 0;
	while (i < 4)
	{
		col_line[i] = grid[i][col];
		i++;
	}
	count_up = count_visible_forward(col_line);
	count_down = count_visible_backward(col_line);
	if (count_up != data[col] || count_down != data[4 + col])
		return (0);
	return (1);
}
