/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:45:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 16:36:05 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void				loop_client(t_client *client)
{
	int				type;
	char			*line;
	int				i;
	static int		type_enum[TYPE_SIZE] = TYPE_ENUM;
	static int		(*type_funct[TYPE_SIZE])(t_client *) = TYPE_FUNCT;

	while (42)
	{
		print_prompt(client);
		type = getnexttype(0, &line);
		printw("%s - %d\n", line, type);
		refresh();
		if (type == QUIT)
			break ;
		if (type == WRONG)
			put_wrong();
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type == type_enum[i])
				type_funct[i](client);
			i++;
		}
	}
}

void				print_prompt(t_client *client)
{
	printw("%s: ", client->nick);
	refresh();
}

void				launch(int (*f)(t_client *), t_client *client)
{
	int				error;

	error = f(client);
	if (!error)
	{
		ft_putstr(GREEN);
		ft_putendl("\n-SUCCESS");
	}
	ft_putchar('\n');
}

void				put_wrong(void)
{
	ft_putstr(RED);
	ft_putendl("\nERROR: wrong command.\n");
}