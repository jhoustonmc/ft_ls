/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:16 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/05 15:54:18 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int	scan_options(int max, char **flags)
{
	int i;
	int j;
	int check;

	i = 1;
	check = 0;
	while (i < max)
	{
		j = 0;
		if (flags[i][0] == '-')
		{
			if (flags[i][j + 1] != '\0')
			while (flags[i][j])
			{
				SET_BIT(check, (flags[i][j] - 'a'));
				j++;
			}
			else
			{
				ft_putendl("Invalid Flag Input '-'");
				return (0);
			}
		}
		else
		{
			ft_putstr("ft_ls: "); 
			ft_putstr(flags[i]);
			ft_putendl(": No such file or directory");
			return (0);
		}
		i++;
	}
	return (check);
}