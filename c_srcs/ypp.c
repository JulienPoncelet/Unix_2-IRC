#include <client.h>

void							inc_y(t_client *client)
{
	int							len;

	len = ft_strlen(client->chan) + ft_strlen(client->nick) +
		ft_strlen(client->buf) + 4;
	while (len)
	{
		YPP(client->y, client->maxy - 1);
		len = len / client->maxx;
	}
}
