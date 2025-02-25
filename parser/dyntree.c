/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:09:29 by lray              #+#    #+#             */
/*   Updated: 2023/08/14 01:03:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dyntree	*dyntree_new(int type, char *value)
{
	t_dyntree	*node;

	node = (t_dyntree *)malloc(sizeof(t_dyntree));
	if (node != NULL)
	{
		node->type = type;
		node->value = ft_strdup(value);
		if (node->value == NULL)
		{
			ft_puterror("Ft_strdup failed");
			return (NULL);
		}
		node->numChildren = 0;
		node->capacity = DYNTREE_INITIAL_CAP;
		node->children = (t_dyntree **)malloc(node->capacity * sizeof(t_dyntree *));
		if (node->children == NULL)
		{
			ft_puterror("Malloc failed");
			return (NULL);
		}
	}
	return (node);
}

int	dyntree_add(t_dyntree *parent, t_dyntree *child)
{
	if (parent->numChildren == parent->capacity)
	{
		parent->capacity *= 2;
		parent->children = (t_dyntree **)ft_realloc(parent->children, (parent->capacity / 2) * sizeof(t_dyntree *), parent->capacity * sizeof(t_dyntree *));
		if (parent->children == NULL)
		{
			ft_puterror("Realloc failed");
			return (0);
		}
	}
	parent->children[parent->numChildren++] = child;
	return (1);
}

void	dyntree_free(t_dyntree *node)
{
	size_t	i;

	if (node == NULL)
		return ;
	i = 0;
	while (i < node->numChildren)
	{
		dyntree_free(node->children[i++]);
	}
	free(node->children);
	free(node->value);
	free(node);
}
