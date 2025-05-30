#include "cub3d.h"

bool ray_facing_down(double angle)
{
	return angle > 0 && angle < PI;
}

bool ray_facing_up(double angle)
{
	return !ray_facing_down(angle);
}

bool ray_facing_right(double angle)
{
	return angle < 0.5 * PI || angle > 1.5 * PI;
}

bool ray_facing_left(double angle)
{
	return !ray_facing_right(angle);
}
