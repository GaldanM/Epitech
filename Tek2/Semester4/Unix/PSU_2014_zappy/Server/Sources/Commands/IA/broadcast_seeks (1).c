#include 	"server.h"

int			seek_north(t_player *dest, int new_y, int new_x)
{
	int		rd;
	int		rs;

	rd = dest->y - new_y;
	rs = new_x - dest->x;
	printf("NORTH :");
	return (calc_angle(rd, rs));
}

int			seek_east(t_player *dest, int new_y, int new_x)
{
	int		rd;
	int		rs;

	rd = new_x - dest->x;
	rs = new_y - dest->y;
	printf("EAST :");
	return (calc_angle(rd, rs));
}

int			seek_west(t_player *dest, int new_y, int new_x)
{
	int		rd;
	int		rs;

	rd = dest->x - new_x;
	rs = dest->y - new_y;
	printf("WEST :");
	return (calc_angle(rd, rs));
}

int			seek_south(t_player *dest, int new_y, int new_x)
{
	int		rd;
	int		rs;

	rd = new_y - dest->y;
	rs = dest->x - new_x;
	printf("SOUTH :");
	return (calc_angle(rd, rs));
}

int			calc_angle(int rd, int rs)
{
	float	sd;
	float	angle;

	sd = sqrt(pow(rd, 2) + pow(rs, 2));
	angle = asin(rs/sd) * (180.0 / M_PI);
	printf("%f\n", angle);
	if (angle < -22.5)
		return (0);
	if (angle > 22.5)
		return (2);
	return (1);
}