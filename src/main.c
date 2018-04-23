#include "../rtv.h"



t_vector make_ray_from_camera(t_glob *g, double x, double y)
{
	t_vector forward;
	t_vector right;
	t_vector up;
	t_vector ray_dir;

	forward = vec_norm(subtract_vec(g->cam_dir, g->cam_pos)); // K
	right = vec_norm(vec_cross(forward, (t_vector) {0, 1, 0})); // I
	up = vec_cross(right, forward); // NOTE: no normalizing in Git project
	ray_dir = (t_vector) {x * right.x + y * up.x + FOV * forward.x,
							x * right.y + y * up.y + FOV * forward.y,
							x * right.z + y * up.z + FOV * forward.z};
	ray_dir = vec_norm(ray_dir);
	//print_vector(ray_dir);
	return (ray_dir);
}

t_vector get_normal(t_intersect *i, t_vector pos)
{
	t_vector normal;
	t_vector a;
	t_vector b;

	//printf("here 1\n");

	if (i->shape->type == CONE || i->shape->type == CYLINDER)
	{
			//printf("here 4\n");

		a = scale_vec(i->shape->dir, (vec_dot(i->ray_dir, i->shape->dir) * i->dist +
			vec_dot(i->v_dist, i->shape->dir)));
			//printf("here 3\n");

		if (i->shape->type == CONE)
			a = scale_vec(a, (1 + pow(tan(i->shape->size), 2)));
		b = subtract_vec(pos, i->shape->pos);
			//printf("here 4\n");

		normal = subtract_vec(b, a);
	} 

	else if (i->shape->type == PLANE)
		normal = i->shape->dir;
	//rintf("here 2\n");
	if (i->shape->type == SPHERE)
		normal = subtract_vec(pos, i->shape->pos);
	normal = vec_norm(normal);
	return (normal);
}

int is_in_shadow(t_shape *cur, t_intersect *i, t_shape *light, t_vector pos)
{
	t_intersect *i2;
	float intersected_any;
	t_vector dist;
	t_shape *curs;

curs = light;
while (curs != NULL)
{
	intersected_any = 0;
	i2 = (t_intersect *)ft_memalloc(sizeof(t_intersect));
	dist = subtract_vec(light->pos, pos);
	i2->dist = sqrtf(vec_dot(dist, dist));
	dist = vec_norm(dist);
	i2->ray_dir = dist;
	while (cur != NULL)
	{
		if (cur != i->shape)
			{
				if (cur->type == PLANE)
					intersected_any = inter_plane(pos, i2, cur);
				if (cur->type == SPHERE)
					intersected_any = inter_sphere(pos, i2, cur);
				if (cur->type == CONE)
					intersected_any = inter_cone(pos, i2, cur);
				if (cur->type == CYLINDER)
					intersected_any = inter_cylinder(pos, i2, cur);
				if (i2->dist > 0.0001 && i2->dist < i->dist)
					return (1);
			}
		cur = cur->next;
	}
	curs = curs->next;
}
	return (0);
}


t_color mix_shadow(t_intersect *i, t_shape *light, float d, float l)
{
	t_color color;

	l = ft_float_01(l * 4.0 * d);
	color = init_clr(0, 0, 0);
	color.r += l * (i->shape->color.r / 255) * (light->color.r / 255);
	color.g += l * (i->shape->color.g / 255) * (light->color.g / 255);
	color.b += l * (i->shape->color.b / 255) * (light->color.b / 255);
	color.r = ft_float_01(color.r);
	color.g = ft_float_01(color.g);
	color.b = ft_float_01(color.b);
	//print_color(color);
	return (color);
}

void get_color(t_glob *g, t_intersect *i, t_shape *light, t_vector ray)
{
	t_vector pos;
	t_vector dist;
	float d;
	t_vector normal;
	float l;

	pos = (t_vector) {g->cam_pos.x + i->dist * ray.x, g->cam_pos.y +
			i->dist * ray.y, g->cam_pos.z + i->dist * ray.z};
	normal = get_normal(i, pos); // ok

	while (light != NULL)
	{
		l = 0.15;
		dist = subtract_vec(light->pos, pos); // okay
		d = ft_float_01(1.0 / sqrtf(sqrtf(vec_dot(dist, dist)))); // okay
		dist = vec_norm(dist); // okay
		if ((is_in_shadow(g->shape_set, i, light, pos)) == 0)
		{
			l += ft_float_01(vec_dot(dist, normal));
			//printf("%f\n", l);
		}
		//print_color(i->color);
		i->color = mix_shadow(i, light, d, l);
		//print_color(i->color);
		light = light->next;
	}
}

void render_pixel(t_glob *g)
{
	t_vector ray_dir;
	// t_ray ray;
	t_intersect *i;
	// int intersected;
	 int int_clr;
	// t_color pixel_color;
	
	int_clr = 0;
	ray_dir = make_ray_from_camera(g, g->c.xu, g->c.yu);
	i = intersection(ray_dir);
	// intersected = does_intersect(i, g->shape_set);
	

	if ((does_intersect(g->shape_set, g->cam_pos, i)) > 0)
		{
			get_color(g, i, g->lights, i->ray_dir);
			//print_color(i->color);
		}
		// if (i->color.r != 0 || i->color.g != 0 || i->color.b != 0)
		// 	print_color(i->color);
	
	//pixel_color = i->color;
	int_clr = make_int_clr(i->color);
	// if (int_clr != 0)
	// 	printf("%i \n", int_clr);
	set_pixel(g->img, g->c.x, g->c.y, int_clr);
	free(i);
}

void render_image(t_glob *g)
{
	g->c.y = 0;
	while (g->c.y < HEIGHT)
	{
		g->c.yu = (HEIGHT - (double)g->c.y * 2) / WIDTH;
		g->c.x = 0;
		while (g->c.x < WIDTH)
		{
			g->c.xu =  (WIDTH - (double)g->c.x * 2) / HEIGHT;
			render_pixel(g);
			// here have same coordinates 
			//render_pixel(g);
			(g->c.x)++;
		}
		(g->c.y)++;
	}
}

int main(void)
{
	t_glob *g;
	
	g = init_glob(); // now you have valid and initialized shape set;
	render_image(g);
	mlx_put_image_to_window(g->m_p, g->w_p, g->img->image, 0, 0);
	mlx_loop(g->m_p);
	return 0;
}
