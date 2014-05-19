/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 11:56:40 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:14:12 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

t_fd						**init_fds(void)
{
	t_fd					**tab_fd;
	int						i;

	if (!(tab_fd = (t_fd **)malloc(sizeof(t_fd *) * MAX_CLIENT)))
	{
		ft_error("serveur", __FILE__, __LINE__);
		return (NULL);
	}
	i = 0;
	while (i < MAX_CLIENT)
	{
		if (!(tab_fd[i] = (t_fd *)malloc(sizeof(t_fd))))
		{
			ft_error("serveur", __FILE__, __LINE__);
			return (NULL);
		}
		clean_fd(tab_fd[i]);
		i++;
	}
	return (tab_fd);
}

void						clean_fd(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
}
