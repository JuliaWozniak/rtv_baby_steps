#include "../rtv.h"

void print_vector(t_vector v)
{
	printf("%f %f %f\n", v.x, v.y, v.z);
}

void print_ray(t_ray r)
{
	printf("new ray\n");
	//print_vector(r.origin);
	print_vector(r.dir);
	//printf("%f\n", r.max_dist);
}




void print_intersection(t_intersect i)
{
	print_ray(i.ray);
	//printf("%f\n", i.t);
	// if (i.shape)
	// 	printf("shpe type %i\n", i.shape->type);
	// print_vector(i.normal);
}


t_ray make_camera_ray(float fov,
						t_point origin,
						t_vector target,
						t_vector target_up_dir,
						float x_screen_pos,
						float y_screen_pos)
{
	t_ray ray;
	t_vector forward;
	t_vector right;
	t_vector up;
	t_vector temp;
	t_vector temp1;
	t_vector temp2;
	float tan_fov;

	forward = vec_norm(subtract_vec(target, origin));
	right = vec_norm(vec_cross(forward, target_up_dir));
	up = vec_norm(vec_cross(right, forward));
	tan_fov = tan(fov * M_PI / 180.0);
	ray.origin = assign_vec(origin); 
	temp = mult_vec_f(right, (x_screen_pos - 0.5) * tan_fov);
	temp2 = add_vec(forward, temp);
	temp1 = mult_vec_f(up, (y_screen_pos - 0.5) * tan_fov);
	ray.dir = add_vec(temp2, temp1);
	ray.dir = vec_norm(ray.dir);
	ray.max_dist = K_RAY_MAX;
	//print_vector(ray.dir);
	return (ray);
}



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
	some_data = new_plane( (t_point) {0, -2, 0},
			(t_vector) {0, 1, 0},
			(t_color) {1, 0.5, 0.8}
		);
	shape->data = some_data;
	shape->next = NULL;
	shape->type = PLANE;
	shape->intersect = &inter_plane;

	return (shape);
}

t_shape *make_shape_set()
{
	t_shape *shape_set;
	t_shape *shape;

	shape_set = NULL;
	shape = make_shape();
	
	shape_set = add_shape(shape_set, shape);

	return (shape_set);
}


int main(void)
{
	t_glob *g;
	t_shape *shape_set;
	
	
	int y;
	int x;
	t_ray ray;
	t_intersect *i;

	g = init_glob();
	shape_set = NULL;

	shape_set = make_shape_set();
	// here you have initialized shape set

	y = 0;
	while (y < HEIGHT)
	{
		float yu;

		yu = 1.0 - ((float)y / (float)(HEIGHT - 1));
		x = 0;
		while (x < WIDTH)
		{
			float xu;

			xu = (float)x / (float)(WIDTH - 1);
			ray = make_camera_ray(30.0,
				(t_point) {0, 0, 0},
				(t_point) {0, 0, 1},
				(t_point) {0, 1, 0},
				xu, yu);
			i = inter_ray(ray);
				int intersected;
				t_color pixel_color;
				intersected = does_intersect(i, shape_set);
				if (intersected)
				{
					pixel_color = i->color;
					int i;
					i = make_int_color(pixel_color);
					set_pixel(g->img, x, y, i);
				}
				
				
			x++;
			
				

		}
		y++;
	}
	mlx_put_image_to_window(g->m_p, g->w_p, g->img->image, 0, 0);
	mlx_loop(g->m_p);

	return 0;
}