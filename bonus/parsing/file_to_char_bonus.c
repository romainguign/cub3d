/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:34:33 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	ft_filedelone(t_file *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->line)
		del(lst->line);
	free (lst);
}

void	ft_fileclear(t_file **lst, void (*del)(void*))
{
	t_file	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_filedelone(*lst, del);
		(*lst) = tmp;
	}
}

static t_file	*ft_filenew(char *content)
{
	t_file	*element_lst;

	element_lst = malloc(sizeof(t_file));
	if (!element_lst)
		return (0);
	element_lst->line = content;
	element_lst->next = NULL;
	return (element_lst);
}

static void	ft_fileadd_back(t_file **lst, t_file *new)
{
	t_file	*e_last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	e_last = *lst;
	while (e_last->next)
		e_last = e_last->next;
	e_last->next = new;
}

void	file_to_char(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_fileadd_back(&map->map_file, ft_filenew(line));
		line = get_next_line(fd);
	}
	get_next_line(-1);
}
