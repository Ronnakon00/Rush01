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
#include "get_input.c"

int	main(int arg, char **data)
{
	int	datatouse[16];
	int grid[4][4];

	if (arg != 2 || read_data_a_organize_data(datatouse, data[1]) != 16)
	{
		write (1, "error", 5);
		return (0);
	}
	/////////////////show result after read_data_a_organize_data/////////////////
	// int j = 0;
	// while (j < 16)
	// {
	// 	char c = datatouse[j] + '0';
	// 	write (1, &c, 1);
	// 	j++;
	// }
}
