#include "../rtv.h"

void print_vector(t_vector v)
{
	printf("%f %f %f\n", v.x, v.y, v.z);
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
	print_vector(ray.dir);
	return (ray);
}








int main(void)
{
	t_glob *g;
	t_shape *shape_set;
	t_plane plane;
	t_plane test;
	int y;
	int x;
	t_ray ray;

	g = init_glob();
	plane = new_plane( (t_point) {0, -2, 0},
			(t_vector) {0, 1, 0},
			(t_color) {1, 0.5, 0.8}
		);
	shape_set = new_shape(PLANE, (void *)&plane);

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
			x++;
		//	printf("%f %f %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
		}
		y++;
	}


	test = *(t_plane *)(shape_set->data);
	//printf("%f\n", test.position.y);
	printf("here\n");
	return 0;
}