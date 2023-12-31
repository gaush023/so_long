/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:49:04 by sagemura          #+#    #+#             */
/*   Updated: 2023/12/29 14:08:38 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


static int	excute_word_counts(char const *s, char c)
{
	size_t	cnt;

	if (s == NULL)
		return (0);
	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static	char *find_next_words(char const *s, char c, char **end_pos)
{
	while (*s == c)
		s++;
	*end_pos = ft_strchr(s, c);
	if (!*end_pos)
		*end_pos = ft_strchr(s, '\0');
	return ((char *)s);
}

static char	*copy_word(char *s, size_t i)
{
	char	*copied_s;
	size_t	len;

	len = ft_strlen(s);
	if (len > i)
		len = i;
	copied_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!copied_s)
		return (NULL);
	copied_s = ft_memcpy(copied_s, s, len);
	copied_s[len] = '\0';
	return (copied_s);
}

static void	free_res_array(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**res;
	char	*start_pos;
	char	*end_pos;
	int		i;

	word_count = excute_word_counts(s, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		start_pos = find_next_words(s, c, &end_pos);
		res[i] = copy_word(start_pos, end_pos - start_pos);
		if (!res[i])
		{
			free_res_array(res, i);
			return (NULL);
		}
		s = end_pos;
		i++;
	}
	res[i] = NULL;
	return (res);
}