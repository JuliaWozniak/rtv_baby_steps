#include "../rtv.h"


t_intersect *intersection(t_vector ray)
{
	t_intersect *new;

	new = (t_intersect *)ft_memalloc(sizeof(t_intersect));
	//printf("%p\n", new);
	new->ray_dir = ray;
	//new->shape = (t_shape *)ft_memalloc(sizeof(t_shape *));
	new->shape = NULL;
	new->color = init_clr(0, 0, 0);
	new->dist = MAX_DIST;
	return (new);
}
