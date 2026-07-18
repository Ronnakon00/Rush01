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
			if (str[i + 1] != ' ')
				break ;
			result[j] = str[i] - '0';
			j++;
			count++;
		}
		i++;
	}
	return (count);
}