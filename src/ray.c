#include "../rtv.h"

t_ray default_ray(void)
{
	t_ray r;

	r.origin = (t_vector) {0, 0, 0};
	r.max_dist = K_RAY_MAX;
	r.dir = (t_vector) {0, 0, 0};
	return (r);
}

t_ray assign_ray(t_ray old)
{
	t_ray new;

	new.origin = assign_vec(old.origin);
	new.max_dist = K_RAY_MAX;
	new.dir = assign_vec(old.dir);
	return (new);
}

t_ray init_ray(t_point p, t_vector d)
{
	t_ray new;

	new.origin = assign_vec(p);
	new.dir = assign_vec(d);
	new.max_dist = K_RAY_MAX;
	return (new);
}

t_point calculate(float f, t_ray r)
{
	t_point p;
	
	p = mult_vec_f(r.dir, f);
	p = add_vec(p, r.origin);
	return (p);
}