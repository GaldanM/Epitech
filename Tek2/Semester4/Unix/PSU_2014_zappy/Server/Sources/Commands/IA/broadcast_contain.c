#include "server.h"

void	south_east(t_param *p, t_player *dest, int new_y, int new_x)
{
	int		res1;
	int		res2;

		res1 = seek_south(dest, new_y, new_x);
		res2 = seek_east(dest, new_y, new_x);
		if (res1 == 0 && res2 == 1)
			dprintf(dest->id, "message %d,%s\n", dest->sound[6], p->cmds[1]);
		else if (res1 == 0 && res2 == 2)
			dprintf(dest->id, "message %d,%s\n", dest->sound[5], p->cmds[1]);
		else if (res1 == 1 && res2 == 2)
			dprintf(dest->id, "message %d,%s\n", dest->sound[4], p->cmds[1]);
}

void	north_east(t_param *p, t_player *dest, int new_y, int new_x)
{
	int		res1;
	int		res2;

		res1 = seek_north(dest, new_y, new_x);
		res2 = seek_east(dest, new_y, new_x);
		if (res1 == 1 && res2 == 0)
			dprintf(dest->id, "message %d,%s\n", dest->sound[0], p->cmds[1]);
		else if (res1 == 2 && res2 == 0)
			dprintf(dest->id, "message %d,%s\n", dest->sound[7], p->cmds[1]);
		else if (res1 == 2 && res2 == 1)
			dprintf(dest->id, "message %d,%s\n", dest->sound[6], p->cmds[1]);
}

void	south_west(t_param *p, t_player *dest, int new_y, int new_x)
{
	int		res1;
	int		res2;
	
res1 = seek_south(dest, new_y, new_x);
		res2 = seek_west(dest, new_y, new_x);
		if (res1 == 1 && res2 == 0)
			dprintf(dest->id, "message %d,%s\n", dest->sound[4], p->cmds[1]);
		else if (res1 == 2 && res2 == 0)
			dprintf(dest->id, "message %d,%s\n", dest->sound[3], p->cmds[1]);
		else if (res1 == 2 && res2 == 1)
			dprintf(dest->id, "message %d,%s\n", dest->sound[2], p->cmds[1]);
}

void	north_west(t_param *p, t_player *dest, int new_y, int new_x)
{
	int		res1;
	int		res2;

		res1 = seek_north(dest, new_y, new_x);
		res2 = seek_west(dest, new_y, new_x);
		if (res1 == 0 && res2 == 1)
			dprintf(dest->id, "message %d,%s\n", dest->sound[2], p->cmds[1]);
		else if (res1 == 0 && res2 == 2)
			dprintf(dest->id, "message %d,%s\n", dest->sound[1], p->cmds[1]);
		else if (res1 == 1 && res2 == 2)
			dprintf(dest->id, "message %d,%s\n", dest->sound[0], p->cmds[1]);
}