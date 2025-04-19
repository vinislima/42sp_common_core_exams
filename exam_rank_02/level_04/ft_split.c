/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:33:25 by vinda-si          #+#    #+#             */
/*   Updated: 2025/04/18 20:57:05 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_wordlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return(i);
}

char	*word_dupe(char *str)
{
	int		i = 0;
	int		len = ft_wordlen(str);
	char	*word = malloc(sizeof(char) * (len + 1));

	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int	word_index = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int	count_words(char *str)
{
	int	num_words = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int	num_words;
	char **array;

	num_words = count_words(str);
	array = malloc(sizeof(char *) * num_words + 1);

	array[num_words] = 0;
	fill_words(array, str);
	return (array);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	char	**split;
// 	int		i;

// 	if (argc == 2)
// 	{
// 		split = ft_split(argv[1]);
// 			printf("%s ", split[0]);
// 		i = 1;
// 		while (split[i] != 0)
// 		{
// 			printf("%s ", split[i]);
// 			i++;
// 		}
// 		printf("%s", split[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }