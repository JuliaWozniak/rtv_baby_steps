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

t_intersect *intersection(t_vector ray)
{
	t_intersect *new;

	new = (t_intersect *)ft_memalloc(sizeof(t_intersect));
	new->ray_dir = ray;
	new->shape = NULL;
	new->color = init_clr(0, 0, 0);
	new->dist = MAX_DIST;
	return (new);
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

t_shape *init_light(t_point pos)
{
	t_shape *light;

	light = (t_shape *)ft_memalloc(sizeof(t_shape));
	light->pos = pos;
	light->color = (t_color) {250, 250, 250};
	light->next = NULL;
	return (light);
}

t_shape *init_cylinder()
{
	t_shape *cyl;
	 
	cyl = (t_shape *)ft_memalloc(sizeof(t_shape));
	cyl->pos = (t_point) {40, 0, -20};
	cyl->dir = (t_vector) {0, 1, 0};
	cyl->color = (t_color) {50, 250, 0};
	cyl->next = NULL;
	cyl->type = CYLINDER;
	cyl->size = 25;
	return (cyl);
}

t_shape *init_plane(t_point pos, t_vector dir, t_color c)
{
	t_shape *plane;
	 
	plane = (t_shape *)ft_memalloc(sizeof(t_shape));
	plane->pos = pos;
	plane->dir = dir;
	plane->color = c;
	plane->next = NULL;
	plane->type = PLANE;
	return (plane);
}

t_shape *init_sphere(t_point pos, t_color c)
{
	t_shape *sphere;

	sphere = (t_shape *)ft_memalloc(sizeof(t_shape));
	sphere->pos = pos;
	sphere->color = c;
	sphere->next = NULL;
	sphere->size = 30;
	sphere->type = SPHERE;
	return (sphere);
}

t_shape *scene_1()
{
	t_shape *shape_set;
	t_shape *shape;

	shape_set = NULL;
	shape = init_plane((t_point) {0, 0, 200}, (t_vector) {0, 0, -1},(t_color){130, 130, 130});
	shape_set = add_shape(shape_set, shape);
	shape = init_plane((t_point) {0, 0, -700}, (t_vector) {0, 0, 1},(t_color){130, 200, 240});
	shape_set = add_shape(shape_set, shape);


	shape = init_sphere((t_point) {-12, 25, 5}, (t_color){0, 250, 250});
	shape_set = add_shape(shape_set, shape);

	shape = init_sphere((t_point) {8, -53, -44}, (t_color){190, 140, 250});
	shape_set = add_shape(shape_set, shape);
		shape = init_cone();
	shape_set = add_shape(shape_set, shape);
	shape = init_cylinder();
	shape_set = add_shape(shape_set, shape);
	return (shape_set);
	return (shape_set);
}

// t_shape *scene_1()
// {
// 	t_shape *shape_set;
// 	t_shape *shape;

// 	shape_set = NULL;
// 	// shape = init_plane((t_point) {0, 0, 0}, (t_vector) {1, 0, -0.9},(t_color){100, 0, 100});
// 	// shape_set = add_shape(shape_set, shape);
// 	shape = init_sphere((t_point) {40, 60, 80}, (t_color){0, 200, 100});
// 	shape_set = add_shape(shape_set, shape);
// 	shape = init_sphere((t_point) {-70, 0, 60}, (t_color){10, 120, 180});
// 	shape_set = add_shape(shape_set, shape);
// 	shape = init_cone();
// 	shape_set = add_shape(shape_set, shape);
// 	shape = init_cylinder();
// 	shape_set = add_shape(shape_set, shape);
// 	return (shape_set);
// }

t_shape *make_shape_set() // later will read input data, validate it and show errors if necessary
{
	t_shape *shape_set;

	shape_set = scene_1();
	return (shape_set);
}

t_shape *make_lights()
{
	t_shape *lights;
	t_shape *l;

	lights = NULL;
	l = init_light((t_point){-40, 60, -10});
	lights = add_light(lights, l);
	l = init_light((t_point){100, 70, -10});
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
	g->cam_dir = (t_vector) {1, -1, 1};
	g->cam_pos = (t_point) {-100, -20, -200};
	g->lights = make_lights();
	if (g->shape_set == NULL)
		; // show relevant error and exit program;
	return (g);
}
