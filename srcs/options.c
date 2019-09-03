/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_prac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 06:28:59 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/03 17:02:34 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void	l_flag(DIR *dir, struct mine loop, struct dirent *had)
{
	while ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		if (loop.data[0] != '.')
		{
			putmodes(loop.data);
			ft_putendl(loop.data);
		}
	}
}

void R_flag(DIR *dir, struct mine loop,  struct dirent *entry, int indent)
{
	int i;
	while ((entry = readdir(dir)) != NULL) 
	{
		if (entry->d_type == DT_DIR) 
		{
			char	path[1024];
			i = 0;
			if (ft_strcmp(entry->d_name, ".") == 0 || ft_strcmp(entry->d_name, "..") == 0)
				continue;
			loop.data = entry->d_name;
//			ft_putstr(name);
//			ft_putstr(entry->d_name);
			snprintf(path, sizeof(path), "%s/%s", entry->d_name, entry->d_name);
//			indent_print(indent);
//			ft_putendl(loop.data);
			printf("%*s[%s]\n", indent, "", entry->d_name);
            R_flag(dir, loop, entry, indent);
		}
	   	else 
			printf("%*s%s\t", indent, "", loop.data);
	}
	closedir(dir);
}

void	no_flags(DIR *dir, struct mine loop, struct dirent *had)
{
	if ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		if (loop.data[0] != '.')
			ft_putendl(loop.data);
		no_flags(dir, loop, had);
	}
}

void	a_flags(DIR *dir, struct mine loop, struct dirent *had)
{
	if ((had = readdir(dir)) != NULL)
	{
		loop.data = had->d_name;
		ft_putendl(loop.data);
		a_flags(dir, loop, had);
	}
}
