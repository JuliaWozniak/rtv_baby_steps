#include "../rtv.h"


t_vector calculate_ray_dir(t_glob *g,
						t_vector forward,
						t_vector right,
						t_vector up)
{
	t_vector dir;
	t_vector temp;
	t_vector temp1;
	t_vector temp2;
	float tan_fov;

	tan_fov = tan(g->fov * M_PI / 180.0);
	temp = mult_vec_f(right, (g->c.xu) * tan_fov);
	temp2 = add_vec(forward, temp);
	temp1 = mult_vec_f(up, (g->c.yu) * tan_fov);
	dir = add_vec(temp2, temp1);
	return (dir); // one variable easily removes when return add vectors without dir
}



t_ray make_ray_from_camera( t_glob *g,
						t_point origin,
						t_vector target,
						t_vector target_up_dir)
{
	t_ray ray;
	t_vector forward;
	t_vector right;
	t_vector up;

	forward = vec_norm(subtract_vec(target, origin));
	right = vec_norm(vec_cross(forward, target_up_dir));
	up = vec_norm(vec_cross(right, forward));
	ray.origin = origin; 
	ray.dir = calculate_ray_dir(g, forward, right, up);
	ray.dir = vec_norm(ray.dir);
	ray.max_dist = K_RAY_MAX;
	return (ray);
}

void render_pixel(t_glob *g)
{
	t_ray ray;
	t_intersect *i;
	int intersected;
	int int_clr;
	t_color pixel_color;

	ray = make_ray_from_camera(g,
				(t_point) {0, 0, 0},
				(t_point) {0, 0, 1},
				(t_point) {0, 1, 0});
	i = inter_ray(ray);
	intersected = does_intersect(i, g->shape_set);
	if (intersected)
	{
		pixel_color = i->color;
		int_clr = make_int_clr(pixel_color);
		set_pixel(g->img, g->c.x, g->c.y, int_clr);
	}
}

void render_image(t_glob *g)
{
	g->c.y = 0;
	while (g->c.y < HEIGHT)
	{
		g->c.yu = ((1.0 - ((float)g->c.y / (float)(HEIGHT - 1)) - 0.5) * 2);
		g->c.x = 0;
		while (g->c.x < WIDTH)
		{
			g->c.xu = ((float)g->c.x / (float)(WIDTH - 1) - 0.5) * 2;
			render_pixel(g);
			//printf("%f %f\n", g->c.xu, g->c.yu);
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
