/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:49:50 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/05 16:03:21 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int		main(int argc, char **argv)
{
	struct dirent	*dir;
	struct s_arg	*pole;
	DIR				*folder;
	int				flags;

	pole = NULL;
	dir = NULL;
	folder = opendir(".");
	if (argv[1] == NULL)
		flags = -1;
	else
		flags = scan_options(argc, argv);
	print_files(folder, pole, dir, flags);
	closedir(folder);
	return (0);
}
