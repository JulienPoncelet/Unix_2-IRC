/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 20:45:45 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/21 18:20:33 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void				loop_client(t_client *client)
{
	int				type;
	int				i;
	static int		type_enum[TYPE_SIZE] = TYPE_ENUM;
	static char		*(*type_funct[TYPE_SIZE])(t_client *) = TYPE_FUNCT;
	char			*error;

	while (42)
	{
		print_prompt(client);
		while ((type = ft_select(client)) == -1)
			;
		refresh();
		if (type == QUIT)
			break ;
		error = NULL;
		i = 0;
		while (i < TYPE_SIZE)
		{
			if (type == type_enum[i])
				error = type_funct[i](client);
			i++;
		}
		put_error(client, error);
	}
}

void				print_prompt(t_client *client)
{
	mvprintw(client->y, 0, "%s: ", client->nick);
	refresh();
}

char				*wrong(t_client *client)
{
	attron(COLOR_PAIR(1));
	mvprintw(client->y, 0, "ERROR: wrong command\n");
	attron(COLOR_PAIR(2));
	YPP(client->y,  client->maxy - 1);
	wmove(client->win, client->y, 0);
	return (0);
}

void				put_error(t_client *client, char *error)
{
	if (error)
	{
		attron(COLOR_PAIR(1));
		mvprintw(client->y, 0, "ERROR: %s\n", error);
		attron(COLOR_PAIR(2));
		YPP(client->y,  client->maxy - 1);
		wmove(client->win, client->y, 0);
	}
}
