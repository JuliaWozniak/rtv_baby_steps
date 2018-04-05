#include "../rtv.h"

// int inter_plane(t_intersect *inter, t_plane plane)
// {
// 	float n_dot_d = vec_dot(plane.normal, inter->ray.dir);
// 	if (n_dot_d > 0.0)
// 		return (0);
// 	float t;
// 	float pos;
// 	float orig;
// 	float dir;

// 	pos = vec_dot(plane.position, plane.normal);
// 	orig = vec_dot(inter->ray.origin, plane.normal);
// 	dir = vec_dot(inter->ray.di, plane.normal);
// 	t = (pos - orig) / dir;
// 	if (t >= inter->t || t < K_RAY_MIN)
// 		return (0);
// 	inter->t = t;
// 	inter->shape = plane;
// 	inter->color = plane.color;
// 	inter->normal = plane.normal;
// 	return (1);
// }