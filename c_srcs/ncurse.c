/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 15:46:33 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 16:29:43 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void						init_ncurse(t_client *client)
{
	client->win = initscr();
	noecho();
	cbreak();
	scrollok(client->win, 1);
}
