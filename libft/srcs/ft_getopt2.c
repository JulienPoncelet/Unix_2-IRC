/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 15:35:49 by jponcele          #+#    #+#             */
/*   Updated: 2014/04/28 16:48:35 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				fill_option(char *c, char **ret, char *valid_opt)
{
	int			i;

	i = 0;
	while (valid_opt[i])
	{
		if (valid_opt[i] == c[0])
		{
			*ret = ft_strjoin(*ret, c);
			return (1);
		}
		i++;
	}
	return (0);
}

int				print_illegal(char c, char *error)
{
	ft_putstr_fd("Illegale option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd(error, 2);
	return (-1);
}

int				ft_getopt(char **cmd, char **ret, char *valid_opt, char *error)
{
	int			i;
	int			option;
	int			j;

	i = 0;
	option = 1;
	*ret = "";
	while (cmd[i] && option)
	{
		if (ft_strequ(cmd[i], "--"))
			return (i + 1);
		if (cmd[i][0] != '-' || !cmd[i][1])
			option = 0;
		j = 1;
		while (option && cmd[i][j])
		{
			if (!fill_option(&(cmd[i][j]), ret, valid_opt))
				return (print_illegal(cmd[i][j], error));
			j++;
		}
		i++;
	}
	return ((!option || i == 2) ? i - 1 : i);
}
