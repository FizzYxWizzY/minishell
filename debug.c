/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:31:46 by lray              #+#    #+#             */
/*   Updated: 2023/08/11 23:29:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	db_show_tree(t_tree_node *node, int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		printf("  ");
		i++;
	}
	printf("%s\n", node->value);

	i = 0;
	while (i < MAX_CHILDREN && node->children[i] != NULL)
	{
		db_show_tree(node->children[i], depth + 1);
		i++;
	}
}
