/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 10:19:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 13:58:08 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include				<arpa/inet.h>
# include				<libft.h>
# include				<netdb.h>
# include				<netinet/in.h>
# include				<stdio.h>
# include				<sys/stat.h>
# include				<sys/socket.h>

# define MAX(a, b)		((a > b) ? a : b)

# define S_USAGE		"usage: serveur <port = 1024>"

# define BACKLOG		42
# define DOMAIN			PF_INET
# define FAMILY			AF_INET
# define TYPE			SOCK_STREAM

# define MAX_CLIENT		42

# define SIZE			4096

# define FD_FREE		0
# define FD_SERVEUR		1
# define FD_CLIENT		2

typedef struct			s_fd
{
	int					type;
	int					(*fct_read)();
	int					(*fct_write)();
	char				buf_read[SIZE + 1];
	char				buf_write[SIZE + 1];
}						t_fd;

typedef struct			s_serveur
{
	int					port;
	t_fd				**tab_fds;
	int					max;
	fd_set				fd_read;
	fd_set				fd_write;
	int					select_ret;
}						t_serveur;

/*
**						check_input.c
*/

int						check_input(int ac);

/*
**						t_serveur.c
*/

t_serveur				*init_serveur(int port);
t_serveur				*init_serveur2(t_serveur *serveur, int sd);
int						end_serveur(t_serveur *serveur);

/*
**						t_fd.c
*/

t_fd					**init_fds(void);
void					clean_fd(t_fd *fd);

/*
**						ft socket's functions
*/

int						ft_accept(int sd);
int						ft_bind(int sd, int port);
int						ft_listen(int sd);
int						ft_socket(void);

/*
**						add_client.c
*/

int						add_client(t_serveur *serveur, int sd);

/*
**						loop.c
*/

int						loop(t_serveur *serveur);

/*
**						client_write.c
*/

int						client_read(t_serveur *serveur, int cs);
int						client_write(t_serveur *serveur, int cs);

/*
**						select
*/

void					init_select(t_serveur *serveur);
int						ft_select(t_serveur *serveur);
void					check_select(t_serveur *serveur);

#endif
