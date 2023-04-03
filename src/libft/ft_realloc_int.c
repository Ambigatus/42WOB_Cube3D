/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:41 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/03 17:51:48 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function reallocates memory for an integer array with a new length.
** It takes in the original array tab, the length of the original array len_tab,
** and the amount to be added to the length of the array add_len. It allocates
** memory for a new array of length (len_tab + add_len) and copies the elements
** from the original array to the new array. It then frees the memory allocated
** for the original array and returns a pointer to the new array. If the memory
** allocation for the new array fails, it returns a NULL pointer. */
int	*ft_realloc_int(int *tab, int len_tab, int add_len)
{
	int	*new_tab;
	int	i;

	if (len_tab == 0)
		len_tab++;
	new_tab = malloc(sizeof(int) * (len_tab + add_len));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < len_tab)
	{
		new_tab[i] = tab[i];
		i++;
	}
	free(tab);
	return (new_tab);
}

/* This function takes an array of strings old, an integer len which is the
** number of elements in old, and a string new_line. It reallocates old by
** creating a new array of strings new with an additional element to store
** new_line. It then copies all the elements of old to new, frees old and
** returns new.

** If successful, the function returns a pointer to the new array of
** strings, otherwise it returns NULL. */
char	**ft_realloc_one(char **old, int len, char *new_line)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	ft_free_split(old);
	new[i] = ft_strdup(new_line);
	free(new_line);
	new[++i] = 0;
	return (new);
}

/* Function realloc_set takes a string (line), a new length (new_len) and a
** character (charset) as arguments, and returns a new string with the given
** length. If the allocation is successful, the new string is initialized with
** the characters from the old string, and the remaining characters are set
** to the given character. The old string is then freed and the new string is
** returned. If the allocation fails, the old string is freed and NULL is
** returned. */
char	*realloc_set(char *line, int new_len, char charset)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * new_len + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy_complete(new_line, line, charset, new_len);
	free(line);
	return (new_line);
}
