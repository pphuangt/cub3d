#include "cub3d.h"

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
	{
		*angle = TWO_PI + *angle;
	}
}
