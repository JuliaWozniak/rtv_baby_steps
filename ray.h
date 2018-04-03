#ifndef RAY_H
#define RAY_H

#include "ft_vector.h"
# define K_RAY_MAX 1.0e30f

typedef struct s_ray
{
	t_point origin;
	t_vector dir;
	float max_dist;
}				t_ray;



#endif