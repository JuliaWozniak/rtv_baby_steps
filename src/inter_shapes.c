#include "../rtv.h"

int inter_plane(t_point pos, t_intersect *i, t_shape *shape)
{
	 double dist;

	 dist = (vec_dot(shape->dir, shape->pos) - vec_dot(shape->dir, pos))
	 			/ vec_dot(shape->dir, i->ray_dir);
	 if (dist > 0.0001 && dist < i->dist)
	 {
	 	i->dist = dist;
	 	i->shape = shape;
	 	i->color = shape->color;
	 	return (1);
	 }
		
	return (0);
}

int inter_sphere(t_point pos, t_intersect *i, t_shape *shape)
{
	double dist;
	double disc;
	float var[3];
	double temp;

	 i->v_dist = subtract_vec(pos, shape->pos);
	 var[0] = vec_dot(i->ray_dir, i->ray_dir);
	 var[1] = 2 * vec_dot(i->ray_dir, i->v_dist);
	 var[2] = vec_dot(i->v_dist, i->v_dist) - (shape->size * shape->size);
	 disc = var[1] * var[1] - 4 * var[0] * var[2];
	 if (disc < 0)
	 	return (-1);
	 dist = (-var[1] + sqrtf(disc)) / (2 * var[0]);
	 temp = (-var[1] - sqrtf(disc)) / (2 * var[0]);
	 if (dist > temp)
	 	dist = temp;
	 if (dist < i->dist && dist > 0.0001)
	 {
	 	i->dist = dist;
	 	// printf("here\n");
	 	// printf("%p\n", i->shape);
	 	// printf("%p\n", shape);
	 	i->shape = shape;
	 	// printf("%p\n", i->shape);
	 	// printf("%p\n", shape);
	 	i->color = shape->color;
	 	return (1);
	 }
	 return (0);
}

int inter_cylinder(t_point pos, t_intersect *i, t_shape *shape)
{
	double dist;
	double disc;
	float var[3];
	double temp;

	i->v_dist = subtract_vec(pos, shape->pos);
	var[0] = vec_dot(i->ray_dir, i->ray_dir) - pow(vec_dot(i->ray_dir, vec_norm(shape->dir)), 2);
	var[1] = 2 * (vec_dot(i->ray_dir, i->v_dist) - (vec_dot(i->ray_dir, shape->dir) * vec_dot(i->v_dist, shape->dir)));
	var[2] = vec_dot(i->v_dist, i->v_dist) - pow(vec_dot(i->v_dist, shape->dir), 2) - pow(shape->size, 2);
	disc = var[1] * var[1] - 4 * var[0] * var[2];
	 dist = (-var[1] + sqrtf(disc)) / (2 * var[0]);
	 temp = (-var[1] - sqrtf(disc)) / (2 * var[0]);
	 if (dist > temp)
	 	dist = temp;
	 if (dist < i->dist && dist > 0.0001)
	 {
	 	i->dist = dist;
	 	i->shape = shape;
	 	i->color = shape->color;
	 	return (1);
	 }
	 return (0);
}

int inter_cone(t_point pos, t_intersect *i, t_shape *shape)
{
	double dist;
	double disc;
	float var[3];
	double temp;

	i->v_dist = subtract_vec(pos, shape->pos);
	var[0] = vec_dot(i->ray_dir, i->ray_dir) - (1 + pow(tan(shape->size), 2)) *
			pow(vec_dot(i->ray_dir, vec_norm(shape->dir)), 2);
	var[1] = 2 * (vec_dot(i->ray_dir, i->v_dist) - (1 + pow(tan(shape->size), 2)) *
			vec_dot(i->ray_dir, shape->dir) * vec_dot(i->v_dist, shape->dir));
	var[2] = vec_dot(i->v_dist, i->v_dist) - (1 + pow(tan(shape->size), 2)) *
			pow(vec_dot(i->v_dist, shape->dir), 2);
	disc = var[1] * var[1] - 4 * var[0] * var[2];
	if (disc < 0)
	 	return (-1);
	 dist = (-var[1] + sqrtf(disc)) / (2 * var[0]);
	 temp = (-var[1] - sqrtf(disc)) / (2 * var[0]);
	 if (dist > temp)
	 	dist = temp;
	 if (dist < i->dist && dist > 0.0001)
	 {
	 	i->dist = dist;
	 	i->shape = shape;
	 	i->color = shape->color;
	 	return (1);
	 }
	 return (0);
}
