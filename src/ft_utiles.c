/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcohere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 21:33:04 by vcohere           #+#    #+#             */
/*   Updated: 2015/01/07 21:33:29 by vcohere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			ft_dbtablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char		**ft_delrow(char **tab, char *str)
{
	char	**db;
	int		i;

	db = (char **)malloc(sizeof(char *) * ft_dbtablen(tab));
	i = 0;
	while (i < ft_dbtablen(tab) - 1)
	{
		if (ft_strequ(get_envar(tab[i]), str))
		{
			while (i < ft_dbtablen(tab) - 1)
			{
				db[i] = ft_strdup(tab[i + 1]);
				i++;
			}
		}
		else
		{
			db[i] = ft_strdup(tab[i]);
			i++;
		}
	}
	db[i] = 0;
	return (db);
}

char		**ft_addrow(char **tab, char *str)
{
	char	**db;
	char	*save;
	int		i;

	save = ft_strdup(tab[0]);
	db = (char **)malloc(sizeof(char *) * ft_dbtablen(tab) + 2);
	i = 0;
	while (i < ft_dbtablen(tab))
	{
		db[i] = ft_strdup(tab[i]);
		i++;
	}
	db[i] = ft_strdup(str);
	db[++i] = 0;
	db[0] = ft_strdup(save);
	return (db);
}

void		ft_puterror(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	ft_prompt(1);
}

int			unvalid_entry(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}
	return (1);
}
