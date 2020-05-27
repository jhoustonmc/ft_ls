/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:47 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/14 10:08:41 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void	indent_print(int indent)
{
	int i;

	i = 0;
	while (indent >= i)
	{
		ft_putstr(" ");
		i++;
	}
}
 
void	free_list(t_link *list)
{
	t_link		*head;

	head = list;
	while (head != NULL)
	{
		free(head->data);
		head = head->next;
		free(list);
		list = head;
	}
}

t_link	*arg_store(DIR *dir, t_link *store, struct dirent *entry)
{
	t_link	*temp;

	store = (t_link *)malloc(sizeof(t_link));
	temp = store;
	while ((entry = readdir(dir)) != NULL)
	{
		store->data = entry->d_name;
		store->next = (t_link *)malloc(sizeof(t_link));
		store = store->next;
	}
	store->next = NULL;
	store = temp;
	return (store);
}

void	add_empty_list(t_link *lst)
{
	t_link	*new;
	t_link	*tmp;

	new = (t_link *)malloc(sizeof(t_link));
	new->data = NULL;
	new->next = NULL;
	tmp = lst;
	if (lst->next == NULL)
		lst->next = new;
	else
	{
		while (1 == 1)
		{
			if (tmp->next == NULL)
			{
				tmp->next = new;
				break;
			}
			tmp = tmp->next;
		}
		tmp->next = NULL;
	}
}


void	st_lst(t_link *lst)
{
	char	*store;
	t_link	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if ((ft_strcmp(lst->data, lst->next->data)) > 0)
		{
			store = lst->data;
			lst->data = lst->next->data;
			lst->next->data = store;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst->next = NULL;
	lst = tmp;
}

int		sort_time(char *file, char *file2)
{
	struct stat		buff;
	struct stat		buff2;

	stat(file, &buff);
	stat(file2, &buff2);
	if (buff.st_ctime == buff2.st_ctime)
		return (buff.st_ctim.tv_nsec < buff2.st_ctim.tv_nsec);
	return (buff.st_ctime < buff2.st_ctime);
}

void			t_st_lst(t_link *lst)
{
	char	*store;
	t_link	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if ((sort_time(lst->data, lst->next->data)))
		{
			store = lst->data;
			lst->data = lst->next->data;
			lst->next->data = store;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst->next = NULL;
	lst = tmp;
}

void	r_st_lst(t_link **head)
{
	t_link	*former;
	t_link *current;
	t_link	*latter;

	latter = NULL;
	former = NULL;
	current = *head;
	while (current != NULL)
	{
		latter = current->next;
		current->next = former;
		former = current;
		current = latter;
	}
	*head = former;
	(*head) = (*head)->next;
}
