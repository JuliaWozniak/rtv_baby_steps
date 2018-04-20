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

t_shape *init_cone()
{
	t_shape *cone;
	 
	cone = (t_shape *)ft_memalloc(sizeof(t_shape));
	cone->pos = (t_point) {80, 0, -20};
	cone->dir = (t_vector) {0, 1, 0};
	cone->color = (t_color) {160, 160, 0};
	cone->next = NULL;
	cone->type = CONE;
	cone->size = 10;
	return (cone);
}

t_shape *add_light(t_shape *list, t_shape *new)
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

t_shape *init_light()
{
	t_shape *light;

	light = (t_shape *)ft_memalloc(sizeof(t_shape));
	light->pos = (t_point) {-60, 30, -60};
	light->color = (t_color) {255, 255, 255};
	light->next = NULL;
	return (light);
}

t_shape *init_cylinder()
{
	t_shape *cyl;
	 
	cyl = (t_shape *)ft_memalloc(sizeof(t_shape));
	cyl->pos = (t_point) {80, 0, -20};
	cyl->dir = (t_vector) {0, 1, 0};
	cyl->color = (t_color) {160, 160, 0};
	cyl->next = NULL;
	cyl->type = CYLINDER;
	cyl->size = 10;
	return (cyl);
}

t_shape *init_plane()
{
	t_shape *plane;
	 
	plane = (t_shape *)ft_memalloc(sizeof(t_shape));
	plane->pos = (t_point) {0, 0, 20};
	plane->dir = (t_vector) {0, 0, -1};
	plane->color = (t_color) {160, 160, 160};
	plane->next = NULL;
	plane->type = PLANE;
	return (plane);
}

t_shape *init_sphere()
{
	t_shape *sphere;

	sphere = (t_shape *)ft_memalloc(sizeof(t_shape));
	sphere->pos = (t_point) {40, 0, -20};
	sphere->color = (t_color) {160, 0, 0};
	sphere->next = NULL;
	sphere->size = 25;
	sphere->type = SPHERE;
	return (sphere);
}

t_shape *make_shape_set() // later will read input data, validate it and show errors if necessary
{
	t_shape *shape_set;
	t_shape *shape;

	shape_set = NULL;
	//if (type == PLANE)
	//shape = init_plane();
	//shape_set = add_shape(shape_set, shape);
	shape = init_sphere();
	shape_set = add_shape(shape_set, shape);
	// shape = init_cone();
	// shape_set = add_shape(shape_set, shape);
	//shape = init_cylinder();
	//shape_set = add_shape(shape_set, shape);
	return (shape_set);
}

t_shape *make_lights()
{
	t_shape *lights;
	t_shape *l;

	lights = NULL;
	l = init_light();
	lights = add_light(lights, l);
	return (lights);
}

t_glob	*init_glob(void)
{
	t_glob	*g;

	g = (t_glob *)ft_memalloc(sizeof(t_glob));
	g->m_p = mlx_init();
	g->w_p = mlx_new_window(g->m_p, WIDTH, HEIGHT, "rtv");
	g->img = create_image(g->m_p);
	g->shape_set = make_shape_set();
	g->cam_dir = (t_vector) {0, 0, 1};
	g->cam_pos = (t_point) {0, 0, -250};
	g->lights = make_lights();
	if (g->shape_set == NULL)
		printf("root\n");; // show relevant error and exit program;
	return (g);
}
