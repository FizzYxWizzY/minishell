/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:28:07 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 19:05:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	1) malloc dynarr (t_dynarrstr * 1)
	2) malloc dynarr->array (str * 1) => NULL
	3) malloc dynarr->array[0]

*/

t_dynarrstr	*dynarrstr_init(t_dynarrstr *dynarr)
{
	if (dynarr == NULL)
	{
		dynarr = malloc(sizeof(t_dynarrstr));
		if (dynarr != NULL)
		{
			dynarr->array = malloc(sizeof(char *));
			if (dynarr->array != NULL)
			{
				dynarr->array[0] = malloc(sizeof(char));
				if (dynarr->array[0])
				{
					ft_memset(dynarr->array[0], 0, sizeof(char));
				}
			}
		}
		dynarr->size = 0;
	}
	return (dynarr);
}

int	dynarrstr_add(t_dynarrstr *dynarr, char *value)
{
	int	actual_size;

	if (dynarr == NULL || value == NULL)
		return (0);
	actual_size = ((int)dynarr->size) + 1;
	dynarr->array = ft_realloc(dynarr->array, sizeof(char *) * actual_size, sizeof(char *) * (actual_size + 1));
	dynarr->array[actual_size - 1] = ft_realloc(dynarr->array[actual_size - 1], 1 * sizeof(char), ((int) ft_strlen(value)) + 1);
	ft_strlcpy(dynarr->array[actual_size - 1], value, ft_strlen(value) + 1);
	dynarr->array[actual_size] = NULL;
	dynarr->size++;
	return (1);
}

void	dynarrstr_show(t_dynarrstr *dynarr)
{
	int	i;
	if (dynarr != NULL)
	{
		printf("dynarr size : %ld\n", dynarr->size);
		i = 0;
		while (dynarr->array[i])
		{
			printf("dynarr->array[%d] : %s\n", i, dynarr->array[i]);
			i++;
		}
	}
}

void	dynarrstr_free(t_dynarrstr *dynarr)
{
	int	i;

	i = 0;
	if (dynarr != NULL)
	{
		if (dynarr->array != NULL)
		{
			while (i < (int)(dynarr->size + 1))
			{
				free(dynarr->array[i]);
				i++;
			}
			free(dynarr->array);
		}
		free(dynarr);
	}
}
