#include 	"server.h"

void		push_broadcast(t_param *p, int id)
{
	t_player	*tmp;

	tmp = p->players;
	while (tmp && tmp->id != id)
		tmp = tmp->next;
	if (tmp)
		push_action(&(tmp->actions), broadcast, 7/p->delay, p->cmds);
}

void		broadcast(t_param *p, t_player *src)
{
	t_player	*dest;

	if (src && p->cmds[1])
	{
		dest = p->players->next;
		while (dest)
		{
			if (dest->id != src->id)
				seek_angle(p, src, dest);
			dest = dest->next;
		}
		dprintf(src->id, "ok\n");
	}
}

void		seek_angle(t_param *p, t_player *src, t_player *dest)
{
	int		new_y;
	int		new_x;
	e_bool	direct[2];

	if (src->x == dest->x && src->y == dest->y)
	{
		dprintf(dest->id, "message 0,%s\n", p->cmds[1]);
		return ;
	}
	compare(p, src, dest, direct);
	new_y = get_new_y(p, dest->y, src->y, direct);
	new_x = get_new_x(p, dest->x, src->x, direct);
	if (new_x >= dest->x && new_y >= dest->y)
		south_east(p, dest, new_y, new_x);
	else if (new_x >= dest->x && new_y <= dest->y)
		north_east(p, dest, new_y, new_x);
	else if (new_x <= dest->x && new_y >= dest->y)
		south_west(p, dest, new_y, new_x);
	else if (new_x <= dest->x && new_y <= dest->y)
		north_west(p, dest, new_y, new_x);
}

void		compare(t_param *p, t_player *src, t_player *dest, e_bool direct[2])
{
	int		c_y;
	int		c_x;

	direct[0] = TRUE;
	direct[1] = TRUE;
	c_y = calc_y_circle(p->size_y, src->y, dest->y);
	if (c_y < abs(src->y - dest->y))
		direct[0] = FALSE;
	c_x = calc_x_circle(p->size_x, src->x, dest->x);
	if (c_x < abs(src->x - dest->x))
		direct[1] = FALSE;
}