/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 10:19:09 by jponcele          #+#    #+#             */
/*   Updated: 2014/05/19 16:36:09 by jponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include				<arpa/inet.h>
# include				<ncurses.h>
# include				<get_next_line.h>
# include				<libft.h>
# include				<netdb.h>
# include				<netinet/in.h>
# include				<stdio.h>

# define C_USAGE		"usage: client <host> <port>"

# define DOMAIN			PF_INET
# define FAMILY			AF_INET
# define TYPE			SOCK_STREAM

enum					e_type
{
	MSG, NICK, JOIN, LEAVE, CREATE, LIST, WHO, MP, QUIT, WRONG
};

# define TYPE_ENUM		{NICK, JOIN, LEAVE, CREATE, LIST, WHO, MP}
# define CMD	{"/nick", "/join", "/leave", "/create", "/list", "/who", "/msg"}
# define TYPE_FUNCT		{nick, join, leave, create, list, who, mp}
# define TYPE_SIZE		7

typedef struct			s_client
{
	WINDOW				*win;
	int					sd;
	char				*addr;
	int					port;
	char				*nick;
}						t_client;

/*
**						ncurse.c
*/

void					init_ncurse(t_client *client);

/*
**						check_input.c
*/

int						check_input(int ac, char ***av);

/*
**						t_client.c
*/

t_client				*init_client(char *addr, int port);
void					end_client(t_client *client);

/*
**						ft socket's functions
*/

int						ft_connect(int sd, char *addr, int port);
int						ft_socket(void);

/*
**						loop.c
*/

void					loop_client(t_client *client);
void					print_prompt(t_client *client);
void					put_wrong(void);

/*
**						getnexttype.c
*/

int						getnexttype(int sson, char **line);
char					*get_next_cmd(void);
int						get_type(char *cmd);

/*
**						nickname
*/

int						nick(t_client *client);

/*
**						channel
*/

int						join(t_client *client);
int						create(t_client *client);
int						leave(t_client *client);
int						list(t_client *client);

/*
**						who
*/

int						who(t_client *client);

/*
**						mp
*/

int						mp(t_client *client);

#endif
