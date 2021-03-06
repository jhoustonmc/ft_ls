/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:49:50 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/13 17:54:06 by jhouston         ###   ########.fr       */
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
	dir = NULL;

	if (argc > 1)
		dir = error_check(argc, argv);
	else
		dir = opendir(".");
	flags = scan_options(argc, argv);
	if (!BIT_ACTIVE(flags, COMP('R')))
		print_files(dir, store, sd, flags);
	else
		rec_flag("./", 0, flags);
	closedir(dir);
	return (0);
}
