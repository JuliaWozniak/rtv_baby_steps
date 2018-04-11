#include "../rtv.h"

t_intersect default_intersection(void)
{
	t_intersect new;

	new.ray = default_ray();
	new.t = K_RAY_MAX;
	new.shape = NULL;
	new.color = init_clr(0, 0, 0);
	new.normal = init_vec(0, 0, 0);
	return (new);
}

t_intersect *inter_ray(t_ray ray)
{
	t_intersect *new;

	new = (t_intersect *)ft_memalloc(sizeof(t_intersect));
	new->ray = ray;
	new->t = ray.max_dist;
	new->shape = NULL;
	new->color = init_clr(0, 0, 0);
	new->normal = init_vec(0, 0, 0);
	return (new);
}

int intersected(t_intersect inter)
{
	if (inter.shape == NULL)
		return (0);
	return (1);
}

t_intersect assign_intersection(t_intersect i)
{
	t_intersect new;

	new.ray = i.ray;
	new.t = i.t;
	new.shape = i.shape;
	new.color = i.color;
	new.normal = i.normal;
	return (new);
}

t_point get_position(t_intersect i)
{
	t_point res;

	res = calculate(i.t, i.ray);
	return (res);
}
