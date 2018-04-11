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
