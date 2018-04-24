#include "../rtv.h"

void print_vector(t_vector v)
{
	printf("%f %f %f\n", v.x, v.y, v.z);
}

// void print_ray(t_ray r)
// {
// 	printf("new ray\n");
// 	//print_vector(r.origin);
// 	print_vector(r.dir);
// 	//printf("%f\n", r.max_dist);
// }

void print_color(t_color clr)
{
	printf("%f %f %f \n", clr.r, clr.g, clr.b);
}

