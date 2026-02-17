/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:34:32 by jalosta-          #+#    #+#             */
/*   Updated: 2026/02/17 16:58:34 by jalosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_error_if(bool valid, char *error, char mask)
{
	if (valid == false)
		*error |= mask;
}

static void	free_arrays(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**map_to_tab(t_list **map)
{
	char	**tab;
	int		i;
	int		len;
	t_list	*current;

	len = ft_lstsize(*map);
	tab = malloc(sizeof(char *) * (len + 1));
	if (tab == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	current = *map;
	while (current != NULL)
	{
		tab[i] = ft_strdup(current->content);
		if (tab[i] == NULL)
		{
			free_arrays(tab);
			ft_lstclear(map, free);
			exit(EXIT_FAILURE);
		}
		current = current->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static t_list	*trace_map(int map_fd)
{
	t_list	*head;
	t_list	*node;
	char	*line;

	head = NULL;
	line = get_next_line_trimmed(map_fd);
	while (line != NULL)
	{
		node = ft_lstnew(line);
		if (node == NULL)
		{
			free(line);
			ft_lstclear(&head, free);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&head, node);
		line = get_next_line_trimmed(map_fd);
	}
	return (head);
}

char	evaluate_map(int map_fd)
{
	t_list	*map;
	char	error;
	size_t	width;
	char	**tab;

	map = trace_map(map_fd);
	if (map == NULL)
		return (MAP_ERR_EMPTY);
	width = ft_strlen(map->content);
	error = 0;
	set_error_if(is_rectangular(map, width), &error, MAP_ERR_NOT_RECTANGULAR);
	set_error_if(is_enclosed(map, width), &error, MAP_ERR_NOT_ENCLOSED);
	set_error_if(has_passage(map, EXIT), &error, MAP_ERR_NO_SINGLE_EXIT);
	set_error_if(has_passage(map, START), &error, MAP_ERR_NO_SINGLE_START);
	set_error_if(has_collectible(map), &error, MAP_ERR_NO_COLLECTIBLE);
	if (error == 0)
	{
		tab = map_to_tab(&map);
		if (false == is_navigable(tab))
			return (MAP_ERR_NO_VALID_PATH);
		free_arrays(tab);
	}
	ft_lstclear(&map, free);
	return (error);
}
