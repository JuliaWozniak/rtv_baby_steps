#include "../rtv.h"


t_shape *add_shape(t_shape *list, t_shape *new)
{
	t_shape *cur;

	if (list == NULL)
	{
		list = new;
		return (list);
	}
	cur = list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (list);
}

t_shape *make_shape()
{
	t_shape *shape;
	void *some_data;

	// if shape == plane
	shape = (t_shape *)ft_memalloc(sizeof(t_shape));
	some_data = new_plane( (t_point) {0, -100, 0},
			(t_vector) {0.3, 1, 0},
			(t_color) {1, 0.5, 0.8}
		);
	shape->data = some_data;
	shape->next = NULL;
	shape->type = PLANE;
	shape->intersect = &inter_plane;
	return (shape);
}

t_shape *make_shape_set() // later will read input data, validate it and show errors if necessary
{
	t_shape *shape_set;
	t_shape *shape;

	shape_set = NULL;
	shape = make_shape();
	shape_set = add_shape(shape_set, shape);
	return (shape_set);
}

t_glob	*init_glob(void)
{
	t_glob	*g;

	g = (t_glob *)ft_memalloc(sizeof(t_glob));
	g->m_p = mlx_init();
	g->w_p = mlx_new_window(g->m_p, WIDTH, HEIGHT, "rtv");
	g->img = create_image(g->m_p);
	g->shape_set = make_shape_set();
	g->fov = 30.0;
	if (g->shape_set == NULL)
		; // show relevant error and exit program;
	return (g);
}
