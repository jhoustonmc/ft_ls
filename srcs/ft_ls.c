/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:49:50 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/10 13:35:27 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int		main(int argc, char **argv)
{
	struct dirent	*sd;
	struct s_link	*store;
	DIR				*dir;
	int				flags;

	store = NULL;
	sd = NULL;
	dir = opendir(".");
	flags = scan_options(argc, argv);
	print_files(dir, store, sd, flags);
	closedir(dir);
	return (0);
}
