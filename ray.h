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

t_ray default_ray(void);
t_ray assign_ray(t_ray old);
t_ray init_ray(t_point p, t_vector d);
t_point calculate(float f, t_ray r);


#endif