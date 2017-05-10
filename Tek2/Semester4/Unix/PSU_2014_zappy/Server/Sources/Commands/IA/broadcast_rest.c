#include "server.h"


int			get_new_y(t_param *p, int dest_y, int src_y, e_bool direct[2])
{
	int		new_y;

	if (direct[0] == FALSE)
	{
		if (src_y > dest_y)
			new_y = src_y - p->size_y;
		else
			new_y = src_y + p->size_y;
		return (new_y);
	}
	return (src_y);
}

int			get_new_x(t_param *p, int dest_x, int src_x, e_bool direct[2])
{
	int		new_x;

	if (direct[1] == FALSE)
	{
		if (src_x > dest_x)
			new_x = src_x - p->size_x;
		else
			new_x = src_x + p->size_x;
		return (new_x);
	}
	return (src_x);
}

int			calc_y_circle(int y_max, int y_s, int y_d)
{
	int		res;

	if (y_s <= y_d)
		res = y_max - y_d + y_s;
	else
		res = y_max - y_s + y_d;
	return (res);
}

int			calc_x_circle(int x_max, int x_s, int x_d)
{
	int		res;

	if (x_s <= x_d)
		res = x_max - x_d + x_s;
	else
		res = x_max - x_s + x_d;
	return (res);
}